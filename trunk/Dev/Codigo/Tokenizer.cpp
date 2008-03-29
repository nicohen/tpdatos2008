#include "Tokenizer.h"
#include "FileInfo.h"
#include "Token.h"
#include "Utils.h"
#include "IOException.h"

namespace Parcers{

	Tokenizer::Tokenizer(FileManager::FileInfo* fileInfo, char delimiters[], int delimitersSize) throw (FileManager::IOException) {
		_delimitersSize= delimitersSize;
		_fileInfo= fileInfo;
		_delimiters= delimiters;
		fileInfo->open();
		fileInfo->read(&_actual,1);
	}

	Token* Tokenizer::getNextToken(bool ignoreDelimiters){
		char buffer[128];
		int i=1;
		if (_actual==0){
			return NULL;
		}
		buffer[0]=_actual;
		if (!ignoreDelimiters && this->isInList(_actual,_delimiters,_delimitersSize)){
			buffer[1]=0;
			_fileInfo->read(&_actual,1);
		}else{
			_fileInfo->read(&_actual,1);
			try{
				while (!this->isInList(_actual,_delimiters,_delimitersSize)){
					buffer[i]=_actual;
					i++;
					_fileInfo->read(&_actual,1);
				}	
			}catch (FileManager::IOException e){
				_actual=0;
			}
			buffer[i]=0;
		}
		return new Token(cloneStr(buffer),1);
	}

	bool Tokenizer::isInList(char item, char* list, int listSize){
		int i=0;
		while((item!=list[i])&&(i<listSize)){
			i++;
		}
		return i!=listSize;
	}

	Tokenizer::~Tokenizer(){
		_fileInfo->close();
	}
}
