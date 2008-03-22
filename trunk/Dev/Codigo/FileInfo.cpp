#include "FileInfo.h"

FileInfo::FileInfo(char* fileName){
	_file= NULL;
	_name= cloneStr(fileName);
}

FileInfo::~FileInfo(){
	free(_name);
	if (_file!=NULL){
		fclose(_file);
	}
}
