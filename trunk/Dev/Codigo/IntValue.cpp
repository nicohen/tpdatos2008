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

DataType* IntValue::getType(){
	return (DataType*)new IntType();
}

IntValue::~IntValue()
{
}

bool IntValue::equals(DataValue* other){
	IntValue* otherint;
	if(this->getType()->getUniqueIdentifier()!=other->getType()->getUniqueIdentifier()){
		return false;
	}else{
		otherint=(IntValue*)other;
		return this->getInt()==otherint->getInt();
	}
}

void IntValue::deserialize(char* data){
	memcpy(&this->_value,data,sizeof(int));
}

char* IntValue::serialize(){
	char* data;
	data=(char*) malloc(sizeof(int));
	memcpy(data,(char*)&this->_value,sizeof(int));
	return data;
}

int IntValue::getInt(){
	return this->_value;
}
