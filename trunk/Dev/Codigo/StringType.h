#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include "DataType.h"

class StringType: public DataType
{
public:
	StringType();
	virtual bool isInstanceOf(void* anObject);
	virtual ~StringType();
};

#endif /*STRINGTYPE_H_*/
