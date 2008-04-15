#include "StringValue.h"
#include <string>
StringValue::StringValue(char* text)
{
	this->_value=cloneStr(text);
}

StringValue::~StringValue()
{
	delete(this->_value);
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

char* StringValue::serialize(){
	char* data;
	T_STRING_LENGHT lenght;
	lenght=strlen(this->_value)+1;
	data=(char*)malloc(sizeof(T_STRING_LENGHT)+lenght);
	memcpy(data,(char*)&lenght,sizeof(T_STRING_LENGHT));
	memcpy(data+sizeof(T_STRING_LENGHT),this->_value,lenght);
	return data;
}