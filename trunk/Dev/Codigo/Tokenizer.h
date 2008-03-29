#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#import "FileInfo.h"
#import "Token.h"

namespace Parcers{
	class Tokenizer{
		
		private:
		char _actual;
		char* _delimiters;
		FileManager::FileInfo* _fileInfo;
		
		public:
		Tokenizer(FileManager::FileInfo* fileInfo, char delimiters[]);
		Token* getNextToken(bool ignoreDelimiters);
		virtual ~Tokenizer();
	};
}
#endif /*TOKENIZER_H_*/
