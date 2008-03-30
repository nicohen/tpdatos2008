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
		char** _keyWords;
		int _keyWordsSize;
		
		FileManager::FileInfo* _fileInfo;
		bool isDelimiter(char item);
		bool isKeyWord(char* item);
		
		public:
		Tokenizer(FileManager::FileInfo *fileInfo, char delimiters[], int delimitersSize, char* keyWords[], int keyWorsSize) throw (FileManager::IOException);
		Token* getNextToken(bool ignoreDelimiters);
		virtual ~Tokenizer();
		static const int DELIMITER =0;
		static const int KEYWORD =1;
		static const int OTHER= 2;
		
	};
}
#endif /*TOKENIZER_H_*/
