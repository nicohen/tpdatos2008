#include "StringType.h"

#include <string>
StringType::StringType(){
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
	DataValue* res=NULL;
	res=this->createNullValue();
	res->deserialize(content);
	return res;
}

DataValue* StringType::createNullValue(){
	return new StringValue("");
}

int StringType::serialize(char* stream){
	char type= DataType::STRING_TYPE;
	memcpy(stream,(char*)&type,sizeof(char));
	return sizeof(char);
}
