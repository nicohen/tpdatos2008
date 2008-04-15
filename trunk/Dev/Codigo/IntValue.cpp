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
/*
void IntValue::deserialize(char* data){
	this->deserializeValue(data,sizeof(int));
}

char* IntValue::serialize(){
	char* data;
	data=(char*)malloc(sizeof(int));
	memcpy(data,(char*)&this->_value,sizeof(int));
	
	this->serializeTo(data);
	return data;
}*/


void IntValue::deserialize(char* data){
	T_STRING_LENGHT lenght;
	memcpy(&lenght,data,sizeof(T_STRING_LENGHT));	
	this->deserializeValue(data+sizeof(T_STRING_LENGHT),lenght);
}

char* IntValue::serialize(){
	char* data;
	T_STRING_LENGHT lenght;
	lenght=this->getSerializationSize();
	data=(char*)malloc(sizeof(T_STRING_LENGHT)+lenght);
	memcpy(data,(char*)&lenght,sizeof(T_STRING_LENGHT));
	
	this->serializeTo(data+sizeof(T_STRING_LENGHT));
	return data;
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
