#ifndef INTTYPE_H_
#define INTTYPE_H_

#include "DataType.h"

class IntType:public DataType
{
public:
	IntType();
	virtual bool isInstanceOf(void* anObject);
	virtual ~IntType();
}; 

#endif /*INTTYPE_H_*/
