#include "UpdateStatement.h"
#include "Utils.h"
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"
//#include <sstream>

UpdateStatement::UpdateStatement(char* filename):Statement(filename){
	_values= new std::vector<DataValue*>();
}


StatementResult* UpdateStatement::execute(DataManager* anIDataManager) {
		StatementResult* statementResult = new StatementResult();
	statementResult->setResult("Intentando Actualizar Registro.");
	return statementResult;
}

void UpdateStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción UpdateStatement");	
}

UpdateStatement::~UpdateStatement(){
}
void UpdateStatement::addValues(std::vector<DataValue*>* valueList){
	vector<DataValue*>::iterator iter;
	for (iter = valueList->begin(); iter != valueList->end(); iter++ ){
		_values->push_back(*iter);
	}
//	delete valueList;
}

void UpdateStatement::setKeyField(DataValue* keyField) {
	this->_keyField = keyField;
}

DataValue* UpdateStatement::getKeyField() {
	return this->_keyField;
}
