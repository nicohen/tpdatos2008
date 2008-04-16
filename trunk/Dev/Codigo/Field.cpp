#include "Field.h"
#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"

Field::Field()
{
	this->_dataType=NULL;
	this->_isMandatory=false;
	this->_isPolyvalent=false;
}

Field::~Field()
{
	delete(this->_dataType);
}

//Getters
bool Field::isMandatory(){
	return this->_isMandatory;
}
bool Field::isPolyvalent(){
	return this->_isPolyvalent;
}
DataType* Field::getDataType(){
	return this->_dataType;	
}

//Setters

void Field::setIsMandatory(bool isMandatory){
	this->_isMandatory=isMandatory;
}
void Field::setIsPolyvalent(bool isPolyvalent){
	this->_isPolyvalent=isPolyvalent;
}

void Field::setDataType(DataType* aDataType){
	this->_dataType=aDataType;	
}

//otros

bool Field::validate(){
	return true;
}

int Field::serialize(char** result){
	
	char* buffer= (char*)malloc(50*sizeof(char));
	int length=0;
	memcpy(buffer,(char*)&_isMandatory,sizeof(bool));
	length+=sizeof(bool);
	memcpy(buffer+length,(char*)&_isPolyvalent,sizeof(bool));
	length+=sizeof(bool);
	length+=_dataType->serialize(buffer+length);
	buffer[length]=0;
	*result=buffer;
	return length;
}
