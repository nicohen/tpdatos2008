#include "StatementResult.h"

StatementResult::StatementResult()
{
}

StatementResult::~StatementResult() {
	free(this->_result);
}

bool StatementResult::wasOk(){
	return true;
}

void StatementResult::setResult(char* result) {
	this->_result = cloneStr(result);
}

char* StatementResult::getResult() {
	return this->_result;
}
/*
vector<Record*>* StatementResult::getFoundRegistries(){
	return 0;
}
*/
void StatementResult::write(OutPutter* outputter){
	outputter->printLine(getResult());
	DEBUG(getResult());
}


