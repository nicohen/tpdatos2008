#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include "stdio.h"

class OutPutter{

	private:
	FileManager::FileInfo* _fileInfoOut;
	FileManager::FileManager* _fileManager;
	
	public:
	OutPutter(FileManager::FileManager* aFileManager);
	virtual ~OutPutter();
	void writeOutputFile(FileManager::FileInfo* inputFile);
	void printLine(char* aMessage);	
};
#endif /*OUTPUTTER_*/
