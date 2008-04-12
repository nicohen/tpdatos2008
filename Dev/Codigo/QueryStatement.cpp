#include "QueryStatement.h"
#include "Utils.h"

QueryStatement::QueryStatement(char* filename):Statement(filename){
}


StatementResult* QueryStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void QueryStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción QueryStatemet");	
}

QueryStatement::~QueryStatement(){
}

void QueryStatement::setFieldNumber(int fieldNumber){
	_fieldNumber= fieldNumber;
}
int QueryStatement::getFieldNumber(){
	return _fieldNumber;
}
void QueryStatement::setValue(DataValue* value){
	_value= value;
}
DataValue* QueryStatement::getValue(){
	return _value;
}
