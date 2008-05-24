#include "IntValue.h"
#include "Utils.h"
#include <sstream>

using namespace std;

IntValue::IntValue(int anInt)
{
	this->_value=anInt;
}

void IntValue::toString(string* buffer) {
	ostringstream oss;
	oss<<this->_value;
	buffer->append(oss.str());
}

char IntValue::getCharType(){
	return DataType::INT_TYPE;
}

IntValue::~IntValue(){
}

bool IntValue::equals(DataValue* other){
	if(DataValue::equals(other)){
		return this->getInt()==((IntValue*)other)->getInt();
	}else{
		return false;	
	}
}

void IntValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	memcpy(&this->_value,data,dataLenght);
}

T_STRING_LENGHT IntValue::getSerializationSize(){
	return sizeof(int);
}

void IntValue::serializeTo(char* buffer){
	memcpy(buffer,(char*)&this->_value,sizeof(int));
}

int IntValue::getInt(){
	return this->_value;
}

bool IntValue::isInstanceOf(DataType* dType){
	return this->getCharType()==dType->getCharType();
}

DataValue* IntValue::clone(){
	return new IntValue(this->_value);
}
