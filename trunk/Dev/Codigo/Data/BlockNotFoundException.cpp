#include "BlockNotFoundException.h"
#include "../Utils.h"


BlockNotFoundException::BlockNotFoundException(char* message) {
	this->_message=cloneStr(message);
}

BlockNotFoundException::~BlockNotFoundException() {
	free(this->_message);
}
