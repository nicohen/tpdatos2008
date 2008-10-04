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
	char* getFileName();
	virtual void writeStatementQuery(OutPutter* outPutter)=0;
	virtual StatementResult* execute(DataManager* dataManager) = 0;
	virtual ~Statement();
	static const int OTHER= 0;
	static const int SECUENCIAL= 1;
	static const int HASH= 2;
	static const int INDEXADO= 3;
	static const int SECINDEXADO= 4;
};

#endif /*STATEMENT_H_*/
