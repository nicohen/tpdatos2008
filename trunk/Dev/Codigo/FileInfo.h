#ifndef FILEINFO_H_
#define FILEINFO_H_

#include "stdio.h"
#include "Utils.h"

class FileInfo{

	private:
	char* _name;
	FILE* _file;
	
	public:
	FileInfo(char* fileName);
	virtual ~FileInfo();
};

#endif /*FILEINFO_H_*/
