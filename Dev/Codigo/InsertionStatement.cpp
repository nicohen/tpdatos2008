#include "InsertionStatement.h"
#include "Utils.h"
#include <stdio.h>

using namespace std;

//Getters
int InsertionStatement::getFileType(){
	return this->_fileType;
}
int InsertionStatement::getSecondaryFieldCount(){
	return this->_secondaryFields->size();
	
}
//Setters
void InsertionStatement::setFileType(int fileType){
	this->_fileType=fileType;
}

InsertionStatement::InsertionStatement(char* fileName):Statement(fileName){
	_secondaryFields=new vector<Field*>();
}

int InsertionStatement::getDataBlockSize(){
	return _dataBlockSize;
}

int InsertionStatement::getIndexSize(){
	return _indexSize;	
}

SecondaryIndex* InsertionStatement::getSecondaryIndex(){
	return _secondaryIndex;
}

vector<Field*>* InsertionStatement::getSecondaryFields(){
	//Usa el constructor de copia de la clase vector
	return new vector<Field*>(*_secondaryFields);
}

void InsertionStatement::addSecondaryField(Field* aField){
	_secondaryFields->push_back(aField);
}

void InsertionStatement::setSecondaryIndex(SecondaryIndex* aSecondaryIndex){
	_secondaryIndex=aSecondaryIndex;
}

void InsertionStatement::setDataBlockSize(int size){
	_dataBlockSize=size;
}
void InsertionStatement::setIndexSize(int size){
	_indexSize=size;
}


void InsertionStatement::clearSecondaryFields(vector<Field*>* secondaryFields){
	vector<Field*>::iterator iter;
	for (iter = secondaryFields->begin(); iter != secondaryFields->end(); iter++ )
	{
		//printf("is mandatory: %i \n",((Field*)*iter)->isMandatory());
		delete ((Field*)*iter);
	}
	secondaryFields->clear();
}

void InsertionStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción InsertionStatement");
}

InsertionStatement::~InsertionStatement()
{
	delete(this->_secondaryIndex);	
	clearSecondaryFields(this->_secondaryFields);
	delete(this->_secondaryFields);
}
