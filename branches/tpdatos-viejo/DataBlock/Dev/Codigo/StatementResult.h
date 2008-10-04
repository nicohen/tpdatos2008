#ifndef STATEMENTRESULT_H_
#define STATEMENTRESULT_H_


#include "Registry.h"
#include "OutPutter.h"
#include <vector>

using namespace std;

class StatementResult{
public:
	
	StatementResult();
	virtual ~StatementResult();
	
	bool wasOk();
	vector<Registry*>* getFoundRegistries();
	void write(OutPutter* outputter);
};

#endif /*STATEMENTRESULT_H_*/
