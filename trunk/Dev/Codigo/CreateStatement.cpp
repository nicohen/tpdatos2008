#include "CreateStatement.h"
#include "Utils.h"
#include <stdio.h>

using namespace std;

//Getters
int CreateStatement::getFileType(){
	return this->_fileType;
}
int CreateStatement::getSecondaryFieldCount(){
	return this->_secondaryFields->size();
	
}
//Setters
void CreateStatement::setFileType(int fileType){
	this->_fileType=fileType;
}

CreateStatement::CreateStatement(char* fileName):Statement(fileName){
	_secondaryFields=new vector<Field*>();
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


void CreateStatement::clearSecondaryFields(vector<Field*>* secondaryFields){
	vector<Field*>::iterator iter;
	for (iter = secondaryFields->begin(); iter != secondaryFields->end(); iter++ )
	{
		//printf("is mandatory: %i \n",((Field*)*iter)->isMandatory());
		delete ((Field*)*iter);
	}
	secondaryFields->clear();
}

void CreateStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción CreateStatement");
}

CreateStatement::~CreateStatement()
{
	delete(this->_secondaryIndex);	
	clearSecondaryFields(this->_secondaryFields);
	delete(this->_secondaryFields);
}
