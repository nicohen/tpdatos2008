#include "StringType.h"

#include <string>
StringType::StringType()
{
}

bool StringType::isInstanceOf(void* anObject){
	return false;	
}
bool StringType::equals(DataType* other){
	return (this->getUniqueIdentifier()==other->getUniqueIdentifier());
}

int StringType::getUniqueIdentifier(){
	return 2;
}

StringType::~StringType()
{
}

DataValue* StringType::deserializeValue(char* content){
	StringValue* res=NULL;
	char* data;
	T_STRING_LENGHT lenght;
	memcpy(&lenght,content,sizeof(T_STRING_LENGHT));
	data=(char*)malloc(lenght);
	memcpy(data,content+sizeof(T_STRING_LENGHT),lenght);
	res= new StringValue(data);
	free(data);
	return res;
}
