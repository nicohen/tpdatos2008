#ifndef DATATYPE_H_
#define DATATYPE_H_

#include "DataValue.h"
class DataValue;
class DataType{
private:
public:
	DataType();
	virtual bool isInstanceOf(void* anObject)=0;
	virtual bool equals(DataType* other)=0;
	virtual int getUniqueIdentifier()=0;
	virtual ~DataType();
	virtual DataValue* deserializeValue(char* content)=0;
	virtual int serialize(char* stream)=0;
	static const char STRING_TYPE= 1;
	static const char INT_TYPE= 2;
};

#endif /*DATATYPE_H_*/
