#include "StringValue.h"

StringValue::StringValue(char* text)
{
	this->_value=cloneStr(text);
}

StringValue::~StringValue()
{
	delete(this->_value);
}

char* StringValue::toString(){
	return "";
}

DataType* StringValue::getType(){
	return (DataType*)new StringType();
}

bool StringValue::equals(DataValue* other){
	return false;
}
