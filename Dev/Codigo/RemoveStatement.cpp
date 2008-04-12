#include "RemoveStatement.h"
#include "Utils.h"

RemoveStatement::RemoveStatement(char* filename):Statement(filename){
}


StatementResult* RemoveStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void RemoveStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción RemoveStatement");	
}

RemoveStatement::~RemoveStatement(){
}

void RemoveStatement::setFieldNumber(int fieldNumber){
	_fieldNumber= fieldNumber;
}
int RemoveStatement::getFieldNumber(){
	return _fieldNumber;
}
void RemoveStatement::setValue(DataValue* value){
	_value= value;
}
DataValue* RemoveStatement::getValue(){
	return _value;
}
