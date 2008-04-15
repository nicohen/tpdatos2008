#ifndef STRINGVALUE_H_
#define STRINGVALUE_H_

#include "DataValue.h"
#include "Utils.h"
#include "StringType.h"

typedef unsigned short T_STRING_LENGHT;
 
class StringValue:public DataValue
{
private:
	char* _value;
public:
	StringValue(char* value);
	virtual ~StringValue();
	
	//otros
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual char* getString();
	virtual char* serialize();
};


#endif /*STRINGVALUE_H_*/
