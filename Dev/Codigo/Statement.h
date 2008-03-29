#ifndef STATEMENT_H_
#define STATEMENT_H_
#include "OutPutter.h"
class Statement
{
private:
	char* _fileName;
public:
	Statement(char* fileName);
	virtual void execute(void* anIDataManager, OutPutter* anOutputter) = 0;
	virtual char* getFileNamess();
	//virtual char* getFileName();
	virtual ~Statement();
};

#endif /*STATEMENT_H_*/
