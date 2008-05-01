#include "StringType.h"

#include <string>
StringType::StringType(){
}

bool StringType::equals(DataType* other){
	return (this->getCharType()==other->getCharType());
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

char StringType::getCharType(){
	return DataType::STRING_TYPE;
}
