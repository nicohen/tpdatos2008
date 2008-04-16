#include "IntType.h"
#include <string.h>

IntType::IntType(){
}

bool IntType::equals(DataType* other){
	return (this->getUniqueIdentifier()==other->getUniqueIdentifier());
}

int IntType::getUniqueIdentifier(){
	return 1;
}

IntType::~IntType()
{
}

DataValue* IntType::deserializeValue(char* content){
	DataValue* res=NULL;
	res=this->createNullValue();
	res->deserialize(content);
	return res;
}

DataValue* IntType::createNullValue(){
	return new IntValue(0);
}

int IntType::serialize(char* stream){
	char type= DataType::INT_TYPE;
	memcpy(stream,(char*)&type,sizeof(char));
	return sizeof(char);
}
