#include "stdafx.h"
#include "TrueAssertion.h"

TrueAssertion::TrueAssertion(bool expr){
	if(!expr){
		reportAssertionFailed();
	}
}
TrueAssertion::TrueAssertion(bool expr,char* message){
	if(!expr){
		reportAssertionFailed();
	}
	_message=message;
}

TrueAssertion::~TrueAssertion(){
	
}

void TrueAssertion::printFailMessage(){
	if(!this->evaluate()){
		printf("Expected \"true\" but was \"false\". Msg: \"%s\"",_message);	
	}		
}


