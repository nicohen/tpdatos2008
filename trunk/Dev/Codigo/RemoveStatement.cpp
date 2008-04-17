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
	string buffer;
	ostringstream ss;
	buffer.append("Buscando registros que coincidan con [");
	ss<<this->_fieldNumber;
	buffer.append(ss.str());
	buffer.append(",");
	this->_value->toString(&buffer);
	buffer.append("] ");
	try{
		DataFile* dataFile= anIDataManager->getFile(this->getFileName());
		int counter = dataFile->removeRecord(_fieldNumber,_value);		
		buffer.append("Se eliminarion ");
		ostringstream sss;
		sss<<counter;
		buffer.append(sss.str());
		buffer.append(" registros del archivo. RES=");
		buffer.append(counter?"1":"0");	
	}catch(FileNotFoundException* ex){
		buffer.append(" Error al eliminar registros (");
		buffer.append(ex->toString());
		buffer.append("). Res=0"); 
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
