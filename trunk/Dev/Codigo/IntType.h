#ifndef INTTYPE_H_
#define INTTYPE_H_

#include "DataType.h"
#include "IntValue.h"


class IntType:public DataType
{

public:
	IntType();
	virtual bool isInstanceOf(void* anObject);
	virtual bool equals(DataType* other);
	virtual int getUniqueIdentifier();
	virtual ~IntType();
	virtual int serialize(char* stream);
	virtual DataValue* deserializeValue(char* content);
	virtual DataValue* createNullValue();
}; 

#endif /*INTTYPE_H_*/
