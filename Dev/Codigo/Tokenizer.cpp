#include "Tokenizer.h"
#include "FileInfo.h"
#include "Token.h"
#include "Utils.h"
#include "string.h"
#include "IOException.h"

using namespace std;
namespace Parsing{

	Tokenizer::Tokenizer(FileManager::FileInfo* fileInfo, char stringIndicator, char delimiters[], int delimitersSize, char* keyWords[], int keyWorsSize) throw (FileManager::IOException){
		_delimitersSize= delimitersSize;
		_fileInfo= fileInfo;
		_sIndicator= stringIndicator;
		_delimiters= delimiters;
		_delimitersSize= delimitersSize;
		_keyWords= keyWords;
		_keyWordsSize= keyWorsSize;
		fileInfo->open();
		fileInfo->read(&_current,1);
		
		this->_readTokens=new vector<Token*>();
	}

	Token* Tokenizer::getNextToken(bool ignoreDelimiters){
		bool isInString=false;
		char buffer[128];
		int type=OTHER;
		char *content;
		int i=0;
		if (_current==0){
			return NULL;
		}
		if (_current==_sIndicator){
			type=STRING;
			isInString= true;
		}else{
			buffer[i]=_current;
			i++;
		}
		if (!ignoreDelimiters && this->isDelimiter(_current)){
			try{
				buffer[1]=0;
				type=DELIMITER;
				_fileInfo->read(&_current,1);
			}catch (FileManager::IOException e){
				_current=0;
			}
		}else{
			try{
				_fileInfo->read(&_current,1);
				while ((isInString && (_current!=_sIndicator))||(!isInString && !this->isDelimiter(_current))){
					if (_current==_sIndicator){
						isInString= false;
					}else{
						buffer[i]=_current;
						i++;
					}
					_fileInfo->read(&_current,1);
				}	
			}catch (FileManager::IOException e){
				_current=0;
			}
			if (_current==_sIndicator){
				try{
					_fileInfo->read(&_current,1);
				}catch (FileManager::IOException e){
				_current=0;
				}
			}
			buffer[i]=0;
		}
		content = cloneStr(buffer);
		if (type!=STRING && type!=DELIMITER){
			if (isNumeric(content)){
				type=NUMBER;
			}else if (isKeyWord(content)){
				type=KEYWORD;
			}
		}

		return this->addToReadTokens(new Token(content,type));
	}

	bool Tokenizer::isDelimiter(char item){
		int i=0;
		while((item!=_delimiters[i])&&(i<_delimitersSize)){
			i++;
		}
		return i!=_delimitersSize;
	}

	bool Tokenizer::isKeyWord(char* item){
		int i=0;
		while((strcmp(item,_keyWords[i])!=0)&&(i<_keyWordsSize)){
			i++;
		}
		return i!=_keyWordsSize;
	}

	Tokenizer::~Tokenizer(){
		printf("~Tokenizer\n");
		_fileInfo->close();
		this->clearReadTokens();
		delete(this->_readTokens);
	}
	
	Token* Tokenizer::addToReadTokens(Token* token){
		this->_readTokens->push_back(token);
		return token;
	}
	
	int Tokenizer::getTokenReadCount(){
		return this->_readTokens->size();
	}
	
	void Tokenizer::clearReadTokens(){
		vector<Token*>::iterator iter;
		for (iter = this->_readTokens->begin(); iter != this->_readTokens->end(); iter++ )
		{
			delete ((Token*)*iter);
		}
		this->_readTokens->clear();
	}
}
