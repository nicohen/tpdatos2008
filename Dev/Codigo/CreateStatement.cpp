#include "CreateStatement.h"
#include "Utils.h"
#include <stdio.h>
#include <sstream>

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
	_secondaryIndex= NULL;
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
void CreateStatement::addSecondaryFields(vector<Field*>* fieldList){
	vector<Field*>::iterator iter;
	for (iter = fieldList->begin(); iter != fieldList->end(); iter++ ){
		_secondaryFields->push_back(*iter);
	}
	delete fieldList;
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

void CreateStatement::writeStatementQuery(OutPutter* outPutter){
	outPutter->printLine("Se ejecutó correctamente CreateStatement");
}

StatementResult* CreateStatement::execute(DataManager* dataManager){
	ostringstream ss;
	
	string buffer;
	DEBUG("Inicio de la ejecución del CreateStatement");
	//Creo el DataFile
	DataFile* dataFile = new DataFile(this->getFileName(),this->getDataBlockSize(),this->getFileType(),this->getIndexSize(),this->getSecondaryFieldCount(),this->getSecondaryFields(),this->getSecondaryIndex());
	//Creo el archivo en la carpeta correspondiente
	dataManager->addFile(dataFile);
	StatementResult* sr = new StatementResult();
	buffer.append("'Se creo correctamente el archivo ");
	
	ss<<this->getFileName();
	buffer.append(ss.str());
	buffer.append("' Res=1");
	sr->setResult((char*)buffer.c_str());
	DEBUG("Fin de la ejecución del CreateStatement");
	return sr;
}

CreateStatement::~CreateStatement()
{
	if (_secondaryIndex!=NULL){
		delete(this->_secondaryIndex);
	}	
	clearSecondaryFields(this->_secondaryFields);
	delete(this->_secondaryFields);
}
