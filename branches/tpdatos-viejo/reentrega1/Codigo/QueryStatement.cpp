#include "QueryStatement.h"
#include "Utils.h"
#include "string.h"
#include "Data/RecordsBlock.h"
#include <sstream>
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"

QueryStatement::QueryStatement(char* filename):Statement(filename){
}

StatementResult* QueryStatement::execute(DataManager* dataManager) {
	StatementResult* statementResult = new StatementResult();
	statementResult->setResult("Intentando Consultar Registro.");
	return statementResult;
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
