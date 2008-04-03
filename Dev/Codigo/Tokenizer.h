#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#import "FileInfo.h"
#import "Token.h"
#include "IOException.h"
#include "ITokenizer.h"
#include <vector>

using namespace std;

namespace Parsing{
	
	class Tokenizer:public ITokenizer{
		
		private:
		vector<Token*>* _readTokens;
		char _current;
		char* _delimiters;
		int _delimitersSize;
		char** _keyWords;
		int _keyWordsSize;
		char _sIndicator;
		
		FileManager::FileInfo* _fileInfo;
		bool isDelimiter(char item);
		bool isKeyWord(char* item);
		
		//Métodos necesarios para el manejo de la lista de tokens 
		Token* addToReadTokens(Token* token);
		void clearReadTokens();
		
		public:
		virtual void moveToNextLine(bool passThrowTheFirstNewLine);
		Tokenizer(FileManager::FileInfo *fileInfo, char stringIndicator, char delimiters[], int delimitersSize, char* keyWords[], int keyWorsSize) throw (FileManager::IOException);
		virtual Token* getNextToken(bool ignoreDelimiters);
		int getTokenReadCount();
		virtual ~Tokenizer();
		
		
	};
}
#endif /*TOKENIZER_H_*/
