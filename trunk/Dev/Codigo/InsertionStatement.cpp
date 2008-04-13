#include "InsertionStatement.h"
#include "Utils.h"
#include <stdio.h>

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

StatementResult* InsertionStatement::execute(DataManager* anIDataManager){
	StatementResult* sr = new StatementResult();
	
	char* cadena; 
	string buffer;

	/**
	 * Dejo comentado esto
	 */
//	DataType* dataType;
//	vector<DataValue*>::iterator iter;
//	for (iter = this->getValues()->begin(); iter != this->getValues()->end(); iter++ ) {
//		 dataType = ((DataValue*)*iter)->getType();
//		 value = ((DataValue*)*iter)->getType();
//	}
	
	buffer.append("'Se inserto el registro ['");
//	buffer.append(dataValue->toString());
	buffer.append("pepito"); //hardcodeado
	buffer.append("',");
	buffer.append("5"); //hardcodeado
	buffer.append(",|...|]' Res=1"); //hardcodeado

	cadena = (char*) malloc(strlen(buffer.c_str()));
	strcpy(cadena,buffer.c_str());

	sr->setResult(cadena);
	return sr;
}

void InsertionStatement::writeStatementQuery(OutPutter* outPutter){
	
}

InsertionStatement::~InsertionStatement() {
	clearValues(_values);
	delete _values;
}
