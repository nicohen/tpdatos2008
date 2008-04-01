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
	OutPutter(FileManager::FileInfo* aFileInfoIn, bool verbose);
	virtual ~OutPutter();
	bool getVerbose();
	void setVerbose(bool verbose);
	FileManager::FileInfo* getFileInfoIn();
	void debug(char* aMessage);
	void error(char* aMessage);
	void printLine(char* aMessage);	
	void printLine(char* aMessage, bool verbose);
	void moveInputFile();
};
#endif /*OUTPUTTER_*/
