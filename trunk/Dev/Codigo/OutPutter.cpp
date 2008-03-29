#include "OutPutter.h"

OutPutter::OutPutter(FileManager::FileInfo* _fileInfo, bool _verboise){
	this->fileInfo = _fileInfo;
	this->verboise = _verboise; 
}

OutPutter::~OutPutter(){
}

void OutPutter::print(char* _message) {
	if (this->verboise) {
		printf(_message);
	} else {
		
	}
}
