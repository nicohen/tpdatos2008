#include "OutPutter.h"
#include <time.h>

OutPutter::OutPutter(FileManager::FileInfo* aFileInfo, bool verboise){
	this->_fileInfo = aFileInfo;
	this->_verboise = verboise; 
}

OutPutter::~OutPutter(){
	free(this->_fileInfo);
}

void OutPutter::debug(char* message){
	if (this->_verboise) {
		printf("Debug: %s\n",message);
	}
}

void OutPutter::error(char* message){
	if (this->_verboise) {
		printf("Error: %s\n",message);
	}
}

void OutPutter::printLine(char* message) {
	if (this->_verboise) {
		time_t rawtime;
		struct tm * timeinfo;
		
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		
		printf("[%s] %s\n",asctime(timeinfo),message);
	} else {
		this->_fileInfo->write(message,strlen(message));
	}
}
