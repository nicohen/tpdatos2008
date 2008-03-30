#include "Field.h"

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


