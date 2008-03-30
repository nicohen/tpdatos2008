#include "Tokenizer.h"
#include "FileInfo.h"
#include "Token.h"
#include "Utils.h"
#include "string.h"
#include "IOException.h"

namespace Parsing{

	Tokenizer::Tokenizer(FileManager::FileInfo* fileInfo, char delimiters[], int delimitersSize, char* keyWords[], int keyWorsSize) throw (FileManager::IOException){
		_delimitersSize= delimitersSize;
		_fileInfo= fileInfo;
		_delimiters= delimiters;
		_delimitersSize= delimitersSize;
		_keyWords= keyWords;
		_keyWordsSize= keyWorsSize;
		fileInfo->open();
		fileInfo->read(&_actual,1);
	}

	Token* Tokenizer::getNextToken(bool ignoreDelimiters){
		char buffer[128];
		int type=OTHER;
		char *content;
		int i=1;
		if (_actual==0){
			return NULL;
		}
		buffer[0]=_actual;
		if (!ignoreDelimiters && this->isDelimiter(_actual)){
			try{
				buffer[1]=0;
				type=DELIMITER;
				_fileInfo->read(&_actual,1);
			}catch (FileManager::IOException e){
				_actual=0;
			}
		}else{
			try{
				_fileInfo->read(&_actual,1);
				while (!this->isDelimiter(_actual)){
					buffer[i]=_actual;
					i++;
					_fileInfo->read(&_actual,1);
				}	
			}catch (FileManager::IOException e){
				_actual=0;
			}
			buffer[i]=0;
		}
		content = cloneStr(buffer);
		if (isKeyWord(content)){
			type=KEYWORD;
		}
		return new Token(content,type);
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
		_fileInfo->close();
	}
}
