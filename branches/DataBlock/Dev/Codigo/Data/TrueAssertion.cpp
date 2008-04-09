#include "stdafx.h"
#include "TrueAssertion.h"

TrueAssertion::TrueAssertion(bool expr){
	_message=0;
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
		if(_message!=0){
			printf("Expected \"true\" but was \"false\". Msg: \"%s\"",_message);	
		}else{
			printf("Expected \"true\" but was \"false\"",_message);	
		}
	}		
}


