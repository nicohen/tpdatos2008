#ifndef REMOVESTATEMENT_H_
#define REMOVESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"
#include "DataValue.h"

class RemoveStatement : public Statement{
private:
	int _fieldNumber;
	DataValue* _value;
public:
	//Constructores y destructores 
	RemoveStatement(char* filename);
	virtual ~RemoveStatement();
	
	void setFieldNumber(int fieldNumber);
	int getFieldNumber();
	void setValue(DataValue* value);
	DataValue* getValue();
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*REMOVESTATEMENT_H_*/
