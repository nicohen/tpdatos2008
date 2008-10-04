#ifndef TOKEN_H_
#define TOKEN_H_

#import "stdlib.h"

namespace Parsing{

	class Token{
		private:
		char* _content;
		int _type;
		public:
			Token(char* content, int type);
			int getType(void);
			char* getContent(void);
			virtual ~Token();
	};

}
#endif /*TOKEN_H_*/
