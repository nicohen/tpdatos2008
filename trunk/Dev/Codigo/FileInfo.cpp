#include "FileInfo.h"

FileInfo::FileInfo(char* fileName){
	_file= NULL;
	_name= cloneStr(fileName);
}

FileInfo::~FileInfo(){
	
}
