#include "StringType.h"

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

DataValue* StringType::deserializeValue(char* data){
	return new StringValue("aaa");
}
