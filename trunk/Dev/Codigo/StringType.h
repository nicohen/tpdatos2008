#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include "DataType.h"

class StringType: public DataType
{
public:
	StringType();
	virtual ~StringType();
	//Otros
	virtual bool isInstanceOf(void* anObject);
	virtual bool equals(DataType* other);
	virtual int getUniqueIdentifier();
};

#endif /*STRINGTYPE_H_*/
