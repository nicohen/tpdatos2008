#include "Tokenizer.h"
#include "FileInfo.h"

namespace Parcers{

	Tokenizer::Tokenizer(FileManager::FileInfo* fileInfo, char delimiters[]){
		_fileInfo= fileInfo;
		_delimiters= delimiters;
		fileInfo->read(&_actual,1);
	}

	Token* Tokenizer::getNextToken(bool ignoreDelimiters){
	}

	Tokenizer::~Tokenizer(){
	}
}
