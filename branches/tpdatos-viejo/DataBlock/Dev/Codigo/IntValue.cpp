#include "IntValue.h"

IntValue::IntValue(int anInt)
{
	this->_value=anInt;
}

char* IntValue::toString(){
	return "";
}

DataType* IntValue::getType(){
	return (DataType*)new IntType();
}

IntValue::~IntValue()
{
}
