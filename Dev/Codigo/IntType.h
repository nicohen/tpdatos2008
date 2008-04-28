#ifndef INTTYPE_H_
#define INTTYPE_H_

#include "DataType.h"
#include "IntValue.h"


class IntType:public DataType
{

public:
	IntType();
	virtual bool equals(DataType* other);
	virtual ~IntType();
	virtual int serialize(char* stream);
	virtual DataValue* deserializeValue(char* content);
	virtual DataValue* createNullValue();
	virtual char getCharType();
}; 

#endif /*INTTYPE_H_*/
