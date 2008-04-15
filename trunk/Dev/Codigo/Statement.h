#ifndef STATEMENT_H_
#define STATEMENT_H_
#include "OutPutter.h"
#include "StatementResult.h"
#include "DataManager.h"

typedef unsigned short int T_FILETYPE;

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
	static const T_FILETYPE OTHER= 0;
	static const T_FILETYPE SECUENCIAL= 1;
	static const T_FILETYPE HASH= 2;
	static const T_FILETYPE INDEXADO= 3;
	static const T_FILETYPE SECINDEXADO= 4;
};

#endif /*STATEMENT_H_*/
