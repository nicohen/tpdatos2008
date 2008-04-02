#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include "stdio.h"

class OutPutter{

	private:
	FileManager::FileInfo* _fileInfoIn;
	FileManager::FileInfo* _fileInfoOut;
	bool _verbose;
	
	public:
	OutPutter(FileManager::FileManager* aFileManager, FileManager::FileInfo* aFileInfoIn, bool verbose);
	virtual ~OutPutter();
	bool getVerbose();
	FileManager::FileInfo* getInputFile();
	void debug(char* aMessage);
	void error(char* aMessage);
	void printLine(char* aMessage);	
};
#endif /*OUTPUTTER_*/
