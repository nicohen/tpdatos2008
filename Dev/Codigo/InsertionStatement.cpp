#include "InsertionStatement.h"
#include "Utils.h"
#include <stdio.h>
#include "IntValue.h"
#include "StringValue.h"
#include "Data/TypeMismatchException.h"
#include "Data/IdentityException.h"
#include "Data/RecordSizeOverflowException.h"


using namespace std;

//Setters

InsertionStatement::InsertionStatement(char* fileName):Statement(fileName) {
	_values = new vector<DataValue*>();
}

//Otros
vector<DataValue*>* InsertionStatement::getValues(){
	//Usa el constructor de copia de la clase vector
	return new vector<DataValue*>(*_values);
}

void InsertionStatement::addValue(DataValue* aValue){
	_values->push_back(aValue);
}

void InsertionStatement::addValues(std::vector<DataValue*>* valueList){
	vector<DataValue*>::iterator iter;
	for (iter = valueList->begin(); iter != valueList->end(); iter++ ){
		_values->push_back(*iter);
	}
	delete valueList;
}

void InsertionStatement::clearValues(vector<DataValue*>* values){
	vector<DataValue*>::iterator iter;
	for (iter = _values->begin(); iter != _values->end(); iter++ ) {
		delete ((DataValue*)*iter);
	}
	values->clear();
}

StatementResult* InsertionStatement::execute(DataManager* dataManager){
	StatementResult* sr = new StatementResult();	
	char* cadena; 
	string buffer;	
	DEBUG("Inicio de la ejecución del InsertionStatement");
	
	try {
		DataFile* dataFile = dataManager->getFile(this->getFileName());
		Record* record = new Record();
		DataValue* each=NULL;
		vector<DataValue*>::iterator iter;
		for (iter = this->_values->begin(); iter != this->_values->end(); iter++ )
		{
			each=((DataValue*)*iter);
			record->addValue(each);
		}	
		buffer.append("'Intentando insertar el registro ");
		record->toString(&buffer);
		buffer.append("'. ");
		dataFile->insertRecord(record);		
		buffer.append(" Res = 1");
	} catch (TypeMismatchException* e1) {
		buffer.append("'Error al insertar el registro (");
		buffer.append(e1->toString());
		buffer.append(")' Res = 0"); 
	} catch (IdentityException* e2) {
		buffer.append("'Error al insertar el registro (");
		buffer.append(e2->toString());
		buffer.append(")' Res = 0"); 
	} catch(FileNotFoundException* e3){
		buffer.append("'Error al insertar el registro (");
		buffer.append(e3->toString());
		buffer.append(")' Res = 0"); 
	} catch(RecordSizeOverflowException* ex4){
		buffer.append("'Error al insertar el registro (");
		buffer.append(ex4->toString());
		buffer.append(")' Res = 0");
	}

	cadena = cloneStr(buffer.c_str());
	sr->setResult(cadena);
	DEBUG("Fin de la ejecución del InsertionStatement");
	free(cadena);
	return sr;
}

void InsertionStatement::writeStatementQuery(OutPutter* outPutter){
	
}

InsertionStatement::~InsertionStatement() {
	clearValues(_values);
	delete _values;
}
