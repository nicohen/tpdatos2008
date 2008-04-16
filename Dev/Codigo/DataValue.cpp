#include "DataValue.h"

DataValue::DataValue()
{
}

DataValue::~DataValue()
{
}


bool DataValue::equals(DataValue* other){
	return this->getType()->getUniqueIdentifier()==other->getType()->getUniqueIdentifier();
}



void DataValue::deserialize(char* data){
	T_STRING_LENGHT lenght;
	memcpy(&lenght,data,sizeof(T_STRING_LENGHT));	
	this->deserializeValue(data+sizeof(T_STRING_LENGHT),lenght);
}

char* DataValue::serialize(){
	char* data;
	T_STRING_LENGHT lenght;
	lenght=this->getSerializationSize();
	data=(char*)malloc(sizeof(T_STRING_LENGHT)+lenght);
	memcpy(data,(char*)&lenght,sizeof(T_STRING_LENGHT));
	
	this->serializeTo(data+sizeof(T_STRING_LENGHT));
	return data;
}
