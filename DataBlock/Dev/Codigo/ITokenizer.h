#ifndef ITOKENIZER_H_
#define ITOKENIZER_H_

using namespace std;

#include "Token.h"
#include "IOException.h"


namespace Parsing{
	class ITokenizer{
		public:
			ITokenizer() throw (FileManager::IOException);
			virtual ~ITokenizer();
			virtual Token* getNextToken(bool ignoreDelimiters)=0;
			virtual void moveToNextLine(bool stopOnTheFirstChar)=0;
			
			static const int DELIMITER =0;
			static const int KEYWORD =1;
			static const int STRING= 2;
			static const int NUMBER= 3;
			static const int OTHER= 4;
	};
}


#endif /*ITOKENIZER_H_*/
