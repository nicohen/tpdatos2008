#ifndef QUERYSTATEMENT_H_
#define QUERYSTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"
#include "DataValue.h"

class QueryStatement : public Statement{
private:
	int _fieldNumber;
	DataValue* _value;
public:
	//Constructores y destructores 
	QueryStatement(char* filename);
	virtual ~QueryStatement();
	
	void setFieldNumber(int fieldNumber);
	int getFieldNumber();
	void setValue(DataValue* value);
	DataValue* getValue();
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*QUERYSTATEMENT_H_*/
