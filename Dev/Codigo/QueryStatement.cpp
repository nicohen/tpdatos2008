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
	string buffer;
	ostringstream ss;
	DEBUG("Inicio de la ejecución del QueryStatement");
	
	buffer.append("Buscando registros que coincidan con [");
	ss<<this->_fieldNumber;
	buffer.append(ss.str());
	buffer.append(",");
	this->_value->toString(&buffer);
	buffer.append("] ");
	
	DataFile* dFile= dataManager->getFile(this->getFileName());
	vector<Record*>* list= dFile->findRecords(this->getFieldNumber(),this->getValue());
	Record* each=NULL;
	vector<Record*>::iterator iter;
	buffer.append(". Elementos encontrados: ");
	for (iter = list->begin(); iter != list->end(); iter++ ){
		each=((Record*)*iter);
		each->toString(&buffer);
	}
	
	//Preparo el resultado
	StatementResult* sr= new StatementResult();
	sr->setResult((char*)buffer.c_str());
	DEBUG("Fin de la ejecución del QueryStatement");
	return sr;
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
