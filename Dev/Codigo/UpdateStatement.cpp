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
	// obtener bloque por bloque
	// llenar cada RecordBlock con un bloque
	// devuelve un array de bytes
	// tengo que crear un record a partir de un array de bytes que devuelve el recordblock

	bool hasUpdated = false;
	Record* record  = new Record();
	record->addValues(this->_values);
	DataFile* dataFile = anIDataManager->getFile(this->getFileName());
	hasUpdated = dataFile->updateRecord(record);
	
	StatementResult* sr = new StatementResult();
	
	char* cadena; 
	string buffer;
	
//	vector<DataValue*>* dataValues = record->getValues();
//	DataValue* each;
	buffer.append("'Actualizacion de registro ");
//	vector<DataValue*>::iterator iter;
//	for (iter = dataValues->begin(); iter != dataValues->end(); iter++ ){
//		each=((DataValue*)*iter);
//		each->toString(&buffer);
//	}
	record->toString(&buffer);
	buffer.append(" Res = ");
	if (hasUpdated)
		buffer.append("1");
	else
		buffer.append("0");

	cadena = (char*) malloc(strlen(buffer.c_str()));
	strcpy(cadena,buffer.c_str());
	sr->setResult(cadena);

	free(cadena);
	
	return sr;
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
