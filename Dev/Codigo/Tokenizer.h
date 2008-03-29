#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#import "FileInfo.h"
#import "Token.h"
#include "IOException.h"

namespace Parsing{
	class Tokenizer{
		
		private:
		char _actual;
		char* _delimiters;
		int _delimitersSize;
		FileManager::FileInfo* _fileInfo;
		bool isInList(char item, char* list, int listSize);
		
		public:
		Tokenizer(FileManager::FileInfo* fileInfo, char delimiters[], int delimitersSize) throw (FileManager::IOException);
		Token* getNextToken(bool ignoreDelimiters);
		virtual ~Tokenizer();
	};
}
#endif /*TOKENIZER_H_*/
