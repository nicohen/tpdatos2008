#ifndef OUTPUTTER_
#define OUTPUTTER_

#include "FileInfo.h"
#include "stdio.h"

class OutPutter{

	private:
	FileInfo* fileInfo;
	bool verboise;
	
	public:
	OutPutter(FileInfo* _fileInfo, bool _verboise);
	virtual ~OutPutter();
	
	void print(char* _msg);	
};
 

#endif /*OUTPUTTER_*/