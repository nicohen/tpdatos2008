#include "IntType.h"
#include <string.h>

IntType::IntType(){
}

bool IntType::equals(DataType* other){
	return (this->getCharType()==other->getCharType());
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


char IntType::getCharType(){
	return DataType::INT_TYPE;
}
