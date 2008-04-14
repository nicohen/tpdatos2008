#ifndef STRINGVALUE_H_
#define STRINGVALUE_H_

#include "DataValue.h"
#include "Utils.h"
#include "StringType.h"
 
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
	virtual char* toString();
		
};


#endif /*STRINGVALUE_H_*/
