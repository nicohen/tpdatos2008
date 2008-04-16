#include "IntType.h"
#include <string.h>

IntType::IntType()
{
}

bool IntType::isInstanceOf(void* anObject){
	return false;	
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

DataValue* IntType::deserializeValue(char* data){
	IntValue* intvalue=new IntValue(0);
	intvalue->deserialize(data);
	return intvalue;
}

int IntType::serialize(char* stream){
	char type= DataType::INT_TYPE;
	memcpy(stream,(char*)&type,sizeof(char));
	return sizeof(char);
}
