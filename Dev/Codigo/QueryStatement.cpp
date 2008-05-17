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
	bool isFirstElement = true;
	DEBUG_CONDITIONAL("Inicio de la ejecución del QueryStatement");
	
	buffer.append("'Se consultó por registros con valor [");
	this->_value->toString(&buffer);
	buffer.append("] en campo [");
	ss<<this->_fieldNumber;
	buffer.append(ss.str());
	buffer.append("]' ");
	try{
		DataFile* dFile= dataManager->getFile(this->getFileName());
		vector<Record*>* list= dFile->findRecords(this->getFieldNumber(),this->getValue());
		Record* each=NULL;
		vector<Record*>::iterator iter;
		if (list->size()==0){
			buffer.append("Res = 0");
		}else{
			buffer.append("Res = ");
			for (iter = list->begin(); iter != list->end(); iter++ ) {
				each=((Record*)*iter);
				if (isFirstElement) {
					isFirstElement = false;
				} else {
					buffer.append(" - ");
				}
				each->toString(&buffer);
			}
		}
	}catch(FileNotFoundException* ex){
		buffer.append(" Error al buscar registros(");
		buffer.append(ex->toString());
		buffer.append("). Res = 0");
		delete ex;
	}	
	
	//Preparo el resultado
	StatementResult* sr= new StatementResult();
	sr->setResult((char*)buffer.c_str());
	DEBUG_CONDITIONAL("Fin de la ejecución del QueryStatement");
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
