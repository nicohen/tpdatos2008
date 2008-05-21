#include "UpdateStatement.h"
#include "Utils.h"
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"
#include "Data/RecordSizeOverflowException.h"
#include "Data/TypeMismatchException.h"
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
	string preOut;
	string buffer;
	StatementResult* sr = new StatementResult();
	try{
		preOut.append("Intentando actualizar el registro: ");
		record->toString(&preOut);
		DEBUGS(&preOut);
		DataFile* dataFile = anIDataManager->getFile(this->getFileName());
		hasUpdated = dataFile->updateRecord(record);
		buffer.append("'Registro actualizado ");
		record->toString(&buffer);
		buffer.append("' Res = ");
		if (hasUpdated)
			buffer.append("1");
		else
			buffer.append("0");
	}catch(TypeMismatchException* ex1){
		buffer.append(" Error al actualizar registro(");
		buffer.append(ex1->toString());
		buffer.append("). Res = 0"); 
		delete ex1;
	}catch(FileNotFoundException* ex){
		buffer.append(" Error al actualizar registro(");
		buffer.append(ex->toString());
		buffer.append("). Res = 0"); 
		delete ex;
	}catch(RecordSizeOverflowException* ex2){
		buffer.append(" Error al actualizar registro(");
		buffer.append(ex2->toString());
		buffer.append("). Res = 0"); 
		delete ex2;
	}
	sr->setResult(cloneStr(buffer.c_str()));	
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
