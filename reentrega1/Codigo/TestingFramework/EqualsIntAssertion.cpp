#include "EqualsIntAssertion.h"
#include <stdlib.h>
#include <stdio.h>

EqualsIntAssertion::EqualsIntAssertion(int expected, int actual){
		_actual=actual;
		_expected=expected;
		if(_expected!=_actual){
			this->reportAssertionFailed();
		}
	}
	
EqualsIntAssertion::~EqualsIntAssertion(){
	
}

void EqualsIntAssertion::printFailMessage(){
	if(!this->evaluate()){
		printf("Expected: \"%i\",But Was: \"%i\"", this->_expected, this->_actual);	
	}		
}


