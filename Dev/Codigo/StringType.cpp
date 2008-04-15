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

StringType::~StringType(){
}

DataValue* StringType::deserializeValue(char* content){
	StringValue* res=NULL;
	res=new StringValue("");
	res->deserialize(content);
	return res;
}
