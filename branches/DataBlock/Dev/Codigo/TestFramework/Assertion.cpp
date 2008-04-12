#include "stdafx.h"
#include "Assertion.h"

Assertion::Assertion(){
	_passed=true;
}
	
bool Assertion::evaluate(){
	return _passed;
}
	
void Assertion::reportAssertionFailed(){
	this->_passed=false;
}
	
Assertion::~Assertion(){
	
}

