#include "CreateStatement.h"
#include "Utils.h"
#include <stdio.h>

using namespace std;

CreateStatement::CreateStatement()
{
	_secondaryFields=new vector<Field*>();
}

char* CreateStatement::getFileName(){
	return _name;	
}

int CreateStatement::getDataBlockSize(){
	return _dataBlockSize;
}

int CreateStatement::getIndexSize(){
	return _indexSize;	
}

SecondaryIndex* CreateStatement::getSecondaryIndex(){
	return _secondaryIndex;
}

vector<Field*>* CreateStatement::getSecondaryFields(){
	//Usa el constructor de copia de la clase vector
	return new vector<Field*>(*_secondaryFields);
}

void CreateStatement::addSecondaryField(Field* aField){
	_secondaryFields->push_back(aField);
}

void CreateStatement::setSecondaryIndex(SecondaryIndex* aSecondaryIndex){
	_secondaryIndex=aSecondaryIndex;
}

void CreateStatement::setDataBlockSize(int size){
	_dataBlockSize=size;
}
void CreateStatement::setIndexSize(int size){
	_indexSize=size;
}

/*
 * El parametro aName será clonado
 * */
void CreateStatement::setFileName(char* aName){
	_name=cloneStr(aName);
}


void cleanSecondaryFields(vector<Field*>* secondaryFields){
	vector<Field*>::iterator iter;
	for (iter = secondaryFields->begin(); iter != secondaryFields->end(); iter++ )
	{
		printf("is mandatory: %i \n",((Field*)*iter)->isMandatory());
		delete ((Field*)*iter);
	}
	secondaryFields->clear();
/*for (Iter = myVector.begin(); Iter != myVector.end(); Iter++ )
 {
      cout << " " << *Iter;
 }*/
}

CreateStatement::~CreateStatement()
{
	//ToDo: RECORRER Y MATAR CADA UNO DE LOS ELEMENTOS DEL ARRAY
	free(this->_name);
	delete(this->_secondaryIndex);	
	cleanSecondaryFields(this->_secondaryFields);
	delete(this->_secondaryFields);
	//this->_secondaryFields
}
