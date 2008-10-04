#include "EqualsAssertion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EqualsAssertion::EqualsAssertion(char* expected, char* actual){
		_actual=actual;
		_expected=expected;
		if(_expected==0){
			_expected="";
		}
		if(_actual==0){
			_actual="";
		}
		if(strcmp(_expected,_actual)!=0){
			this->reportAssertionFailed();
		}
	}
	
EqualsAssertion::~EqualsAssertion(){
	
}

void EqualsAssertion::printFailMessage(){
	if(!this->evaluate()){
		printf("Expected: \"%s\",But Was: \"%s\"", this->_expected, this->_actual);	
	}		
}

