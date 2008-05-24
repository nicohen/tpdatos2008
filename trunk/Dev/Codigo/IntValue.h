#ifndef INTVALUE_H_
#define INTVALUE_H_

#include "DataValue.h"
#include "IntType.h"
#include <string>

class IntValue:public DataValue
{
private:
	int _value;
protected:
	virtual T_STRING_LENGHT getSerializationSize();
	virtual void serializeTo(char* buffer);	
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght);
public:
	IntValue(int value);
	virtual ~IntValue();
	
	int getInt();
	virtual bool equals(DataValue* other);
	virtual char getCharType();
	virtual void toString(string* buffer);
	virtual bool isInstanceOf(DataType* dType);
	virtual DataValue* clone();
};

#endif /*INTVALUE_H_*/
