#ifndef INTVALUE_H_
#define INTVALUE_H_

#include "DataValue.h"
#include "IntType.h"
#include <string>

class IntValue:public DataValue
{
private:
	int _value;
public:
	IntValue(int value);
	virtual ~IntValue();
	
	void deserialize(char* data);
	int getInt();
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual void toString(string* buffer);
	virtual char* serialize();
	
};

#endif /*INTVALUE_H_*/
