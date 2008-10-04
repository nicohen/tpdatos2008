#include "IntType.h"

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
