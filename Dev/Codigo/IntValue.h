#ifndef INTVALUE_H_
#define INTVALUE_H_

#include "DataValue.h"
#include "IntType.h"

class IntValue:public DataValue
{
private:
	int _value;
public:
	IntValue(int value);
	virtual ~IntValue();
	
	void deserialize(char* data);
	char* serialize();
	int getInt();
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual char* toString();
	
};

#endif /*INTVALUE_H_*/
