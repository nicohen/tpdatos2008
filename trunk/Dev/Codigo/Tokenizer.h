#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#import "FileInfo.h"
#import "Token.h"
#include "IOException.h"

namespace Parsing{
	class Tokenizer{
		
		private:
		char _current;
		char* _delimiters;
		int _delimitersSize;
		char** _keyWords;
		int _keyWordsSize;
		char _sIndicator;
		
		FileManager::FileInfo* _fileInfo;
		bool isDelimiter(char item);
		bool isKeyWord(char* item);
		
		public:
		Tokenizer(FileManager::FileInfo *fileInfo, char stringIndicator, char delimiters[], int delimitersSize, char* keyWords[], int keyWorsSize) throw (FileManager::IOException);
		Token* getNextToken(bool ignoreDelimiters);
		virtual ~Tokenizer();
		static const int DELIMITER =0;
		static const int KEYWORD =1;
		static const int STRING= 2;
		static const int NUMBER= 3;
		static const int OTHER= 4;
		
	};
}
#endif /*TOKENIZER_H_*/
