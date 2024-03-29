#ifndef UPDATESTATEMENT_H_
#define UPDATESTATEMENT_H_

#include "Statement.h"
#include "OutPutter.h"
#include "DataValue.h"
#include <vector>

class UpdateStatement : public Statement{
private:
	DataValue* _keyField;
	std::vector<DataValue*>* _values;
public:
	//Constructores y destructores 
	UpdateStatement(char* filename);
	virtual ~UpdateStatement();
	//Getters
	std::vector<DataValue*>* getValues();
		
	//Otros metodos
	void addValue(DataValue* aValue);
	void addValues(std::vector<DataValue*>* valueList);
	void setKeyField(DataValue* key);
	DataValue* getKeyField();
	void clearValues(vector<DataValue*>* values);
	virtual StatementResult* execute(DataManager* anIDataManager);
	virtual void writeStatementQuery(OutPutter* outPutter);
};

#endif /*UPDATESTATEMENT_H_*/
