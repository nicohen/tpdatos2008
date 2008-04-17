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
	DataFile* dataFile= anIDataManager->getFile(this->getFileName());
	int counter = dataFile->removeRecord(_fieldNumber,_value);
	string buffer;
	buffer.append("Se eliminarion ");
	ostringstream ss;
	ss<<counter;
	buffer.append(ss.str());
	buffer.append(" registros del archivo. RES=");
	buffer.append(counter?"1":"0");	
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
