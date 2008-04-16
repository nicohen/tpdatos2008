#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

#include "DataType.h"
#include "StringValue.h"

class StringValue;

class StringType: public DataType
{
public:
	StringType();
	virtual ~StringType();
	//Otros
	virtual bool equals(DataType* other);
	virtual int getUniqueIdentifier();
	virtual DataValue* deserializeValue(char* content);
	virtual DataValue* createNullValue();
	virtual int serialize(char* stream);
};

#endif /*STRINGTYPE_H_*/
