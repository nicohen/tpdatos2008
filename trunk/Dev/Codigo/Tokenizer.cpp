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
	
	void Tokenizer::moveToNextLine(bool stopOnTheFirstChar){
		try{
			if(stopOnTheFirstChar && _current=='\n'){
				_fileInfo->read(&_current,1);
				return;
			}
			while (_current!=0 && _current!='\n'){
				_fileInfo->read(&_current,1);
			}
			if(_current=='\n'){
				_fileInfo->read(&_current,1);	
			}
		}catch (FileManager::IOException e){
			_current=0;
		}
		return;		
	}
	/*
	Token* Tokenizer::getNextLineToken(){
		char buffer[128];
		int type=OTHER;
		char *content;
		int i=0;
		
		try{
			if(_current=='\n'){
				_fileInfo->read(&_current,1);
			}
			while (_current!='\n'){
				buffer[i]=_current;
				i++;
				_fileInfo->read(&_current,1);
			}
		}catch (FileManager::IOException e){
			_current=0;
		}
		return this->addToReadTokens(new Token(content,type));
	}
*/
	Token* Tokenizer::getNextToken(bool ignoreDelimiters){
		bool isInString=false;
		char buffer[128];
		int type=OTHER;
		char *content;
		int i=0;
		if (_current==0){
			//TODO: llamar al debug
			printf("Tokenizer: Current es null.\n");
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
					printf("current: %c\n",_current);
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
		printf("clonando str: \"%s\".\n",content);
		if (type!=STRING && type!=DELIMITER){
			printf("No es ni STRING ni DELIMITER\n");
			if (isNumeric(content)){
				type=NUMBER;
				printf("es NUMERICO\n");
			}else {
				printf("no es NUMERICO\n");
				if (isKeyWord(content)){
					type=KEYWORD;
					printf("Es KEYWORD\n");
				}	
			}
			printf("No es ni KEYWORD ni NUMERIC\n");
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
		bool found=false;
		//printf("Buscando si es KEYWORD \"%s\".\n",item);
		while(!found && i<_keyWordsSize){
			if(strcmp(item,_keyWords[i])==0){
				found=true;
			}
			//printf("KEYWORD[i]: %s\n",_keyWords[i]);
			i++;
		}
		printf("Resultado de is Keyword: %i\n",found);
		return found;
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
