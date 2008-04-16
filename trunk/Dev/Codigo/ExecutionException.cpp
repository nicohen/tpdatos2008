#include "ExecutionException.h"

ExecutionException::ExecutionException(char* cause){
	_text= cause;
}

ExecutionException::~ExecutionException(){
}
