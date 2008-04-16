#include "StringValue.h"
#include <string>
using namespace std;

StringValue::StringValue(char* text)
{
	this->_value=cloneStr(text);
}

StringValue::~StringValue()
{
	delete(this->_value);
}

void StringValue::toString(string* buffer) {
	buffer->append("'");
	buffer->append(this->_value);
	buffer->append("'");
}

DataType* StringValue::getType(){
	return (DataType*)new StringType();
}

bool StringValue::equals(DataValue* other){
	if(DataValue::equals(other)){
		return (strcmp(this->getString(),((StringValue*)other)->getString())==0);
	}
	return false;
}

char* StringValue::getString(){
	return this->_value;
}

void StringValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	this->_value=(char*)malloc(dataLenght);
	memcpy(this->_value,data,dataLenght);
}

T_STRING_LENGHT StringValue::getSerializationSize(){
	return strlen(this->_value)+1;
}

void StringValue::serializeTo(char* buffer){
	memcpy(buffer,this->_value,strlen(this->_value)+1);
}

bool StringValue::isInstanceOf(DataType* dType){
	return this->getType()->getUniqueIdentifier()==dType->getUniqueIdentifier();
}
