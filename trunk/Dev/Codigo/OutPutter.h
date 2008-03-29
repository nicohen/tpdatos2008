#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include "stdio.h"
#include "iostream.h"

class OutPutter{

	private:
	FileManager::FileInfo* fileInfo;
	bool verboise;
	
	public:
	OutPutter(FileManager::FileInfo* _fileInfo, bool _verboise);
	virtual ~OutPutter();
	
	void printLine(char* _msg);	
};
#endif /*OUTPUTTER_*/
