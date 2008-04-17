#ifndef STATEMENTRESULT_H_
#define STATEMENTRESULT_H_

/*
#include "Registry.h"
*/
#include "OutPutter.h"
#include <vector>

using namespace std;

class StatementResult{

private:
	char* _result;
public:
	StatementResult();
	virtual ~StatementResult();
	
	bool wasOk();
	//vector<Registry*>* getFoundRegistries();
	void write(OutPutter* outputter);
	void setResult(char* result);
	char* getResult();
};

#endif /*STATEMENTRESULT_H_*/
