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

Field::Field(char* byteCode){
	decode(byteCode);
}

void Field::decode(char* byteCode){	
	int counter=0;
	char tipo;
	memcpy(&_isMandatory,byteCode,sizeof(bool));
	counter+=sizeof(bool);
	memcpy(&_isPolyvalent,byteCode+counter,sizeof(bool));
	counter+=sizeof(bool);
	memcpy(&tipo,byteCode+counter,sizeof(char));
	counter+=sizeof(char);
	switch(tipo){
		case DataType::STRING_TYPE:
			_dataType=new StringType();
			break;
		case DataType::INT_TYPE:
			_dataType=new IntType();
			break;
		case DataType::STRUCTURED_TYPE:
			StructureType* sType= new StructureType();
			unsigned short size;
			memcpy(&size,byteCode+counter,sizeof(short));
			counter+=sizeof(short);
			for(int j=0;j<size;j++){
				char type;
				memcpy(&type,byteCode+counter,sizeof(char));
				counter+=sizeof(char);
				switch(type){
					case DataType::STRING_TYPE:
						sType->addType(new StringType());
						break;
					case DataType::INT_TYPE:
						sType->addType(new IntType());
						break;
				}
			}
			_dataType=sType;
			break;
	}
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
	memcpy(buffer+length,(char*)&_isMandatory,sizeof(bool));
	length+=sizeof(bool);
	memcpy(buffer+length,(char*)&_isPolyvalent,sizeof(bool));
	length+=sizeof(bool);
	length+=_dataType->serialize(buffer+length);
	buffer[length]=0;
	*result=buffer;
	return length;
}
