#include "OutPutter.h"

OutPutter::OutPutter(FileManager::FileInfo* _fileInfo, bool _verboise){
	this->fileInfo = _fileInfo;
	this->verboise = _verboise; 
}

OutPutter::~OutPutter(){
	free(this->fileInfo);
}

void OutPutter::trace(char* message){
	if (this->verboise) {
		printf("Debug: %s\n",message);
	}
}

void OutPutter::printLine(char* _message) {
	if (this->verboise) {
		printf("%s\n",_message);
	} else {
		this->fileInfo->write(_message,strlen(_message));
	}
}
