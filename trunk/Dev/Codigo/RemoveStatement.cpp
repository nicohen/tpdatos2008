#include "RemoveStatement.h"
#include "Utils.h"
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"
#include <sstream>
#include "string"

RemoveStatement::RemoveStatement(char* filename):Statement(filename){
}


StatementResult* RemoveStatement::execute(DataManager* anIDataManager){
	vector<Record*>* removedRecords = NULL;
	string buffer;
	bool isFirstElement = true;
	ostringstream ss;
	buffer.append("'Se eliminan registros con valor [");
	this->_value->toString(&buffer);
	buffer.append("] en el campo [");
	ss<<this->_fieldNumber;
	buffer.append(ss.str());
	buffer.append("]' ");
	try{
		DataFile* dataFile= anIDataManager->getFile(this->getFileName());
		removedRecords = dataFile->removeRecord(_fieldNumber,_value);		
		buffer.append("Res = ");
		Record* each = NULL;
		vector<Record*>::iterator iter;
		for (iter = removedRecords->begin(); iter != removedRecords->end(); iter++ ){
			each=((Record*)*iter);
			if (isFirstElement) {
				isFirstElement = false;
			} else {
				buffer.append(" - ");
			}
			each->toString(&buffer);
		}
		buffer.append(removedRecords->size()?"":"0");	
	}catch(FileNotFoundException* ex){
		buffer.append(" Error al eliminar registros (");
		buffer.append(ex->toString());
		buffer.append("). Res = 0"); 
		delete ex;
	}	
	StatementResult* sr= new StatementResult();
	sr->setResult((char*)buffer.c_str());
	return sr;
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
