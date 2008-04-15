#include "DataValue.h"

DataValue::DataValue()
{
}

DataValue::~DataValue()
{
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
