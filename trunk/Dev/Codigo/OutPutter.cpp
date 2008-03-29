#include "OutPutter.h"

OutPutter::OutPutter(FileManager::FileInfo* _fileInfo, bool _verboise){
	this->fileInfo = _fileInfo;
	this->verboise = _verboise; 
}

OutPutter::~OutPutter(){
	free(this->fileInfo);
}

void OutPutter::printLine(char* _message) {
	if (this->verboise) {
		cout<<_message<<endl;
	} else {
		this->fileInfo->write(_message,strlen(_message));
	}
}
