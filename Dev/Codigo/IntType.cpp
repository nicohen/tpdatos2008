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
	int value;
	memcpy(&value,data,sizeof(int));
	return new IntValue(value);
}
