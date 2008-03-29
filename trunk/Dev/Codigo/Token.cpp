#include "Token.h"

namespace Parcers{

	Token::Token(char* content, int type){
		_content= content;
		_type= type;
	}
	
	int Token::getType(void){
		return _type;
	}
	
	char* Token::getContent(void){
		return _content;
	}
	
	Token::~Token(){
		free(_content);
	}

}
