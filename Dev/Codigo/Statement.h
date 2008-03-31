#ifndef STATEMENT_H_
#define STATEMENT_H_
#include "OutPutter.h"
#include "StatementResult.h"
#include "DataManager.h"

class StatementResult;
class Statement
{
private:
	char* _fileName;
public:
	Statement(char* fileName);
	virtual char* getFileNamess();
	//virtual char* getFileName();
	virtual void writeStatementQuery(OutPutter* outPutter)=0;
	virtual StatementResult* execute(DataManager* dataManager) = 0;
	virtual ~Statement();
};

#endif /*STATEMENT_H_*/
