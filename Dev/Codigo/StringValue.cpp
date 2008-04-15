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
	return false;
}

char* StringValue::getString(){
	return this->_value;
}

void StringValue::deserialize(char* data){
	T_STRING_LENGHT lenght;
	memcpy(&lenght,data,sizeof(T_STRING_LENGHT));	
	this->deserializeValue(data,lenght);
}

void StringValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	this->_value=(char*)malloc(dataLenght);
	memcpy(this->_value,data+sizeof(T_STRING_LENGHT),dataLenght);
}


char* StringValue::serialize(){
	char* data;
	T_STRING_LENGHT lenght;
	lenght=this->getSerializationSize();
	data=(char*)malloc(sizeof(T_STRING_LENGHT)+lenght);
	memcpy(data,(char*)&lenght,sizeof(T_STRING_LENGHT));
	
	this->serializeTo(data+sizeof(T_STRING_LENGHT));
	return data;
}

T_STRING_LENGHT StringValue::getSerializationSize(){
	return strlen(this->_value)+1;
}

void StringValue::serializeTo(char* buffer){
	memcpy(buffer,this->_value,strlen(this->_value)+1);
}