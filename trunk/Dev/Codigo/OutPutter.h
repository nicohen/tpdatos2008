#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include <stdio.h>

class OutPutter{

	private:
	FileManager::FileInfo* _fileInfo;
	bool _verboise;
	
	public:
	OutPutter(FileManager::FileInfo* aFileInfo, bool verboise);
	virtual ~OutPutter();
	void debug(char* aMessage);
	void error(char* aMessage);
	void printLine(char* aMessage);	
};
#endif /*OUTPUTTER_*/
