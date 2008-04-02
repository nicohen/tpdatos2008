#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include "stdio.h"

class OutPutter{

	private:
	FileManager::FileInfo* _fileInfoOut;
	FileManager::FileManager* _fileManager;
	bool _verbose;
	
	public:
	OutPutter(FileManager::FileManager* aFileManager, bool verbose);
	virtual ~OutPutter();
	void writeOutputFile(FileManager::FileInfo* inputFile);
	bool getVerbose();
	void debug(char* aMessage);
	void error(char* aMessage);
	void printLine(char* aMessage);	
};
#endif /*OUTPUTTER_*/
