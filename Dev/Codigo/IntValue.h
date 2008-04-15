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
	
	int getInt();
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual void toString(string* buffer);
	virtual char* serialize();
	
	void deserialize(char* data);//Esto va en la clase madre (no es virtual)
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght);
	
	virtual T_STRING_LENGHT getSerializationSize();
	virtual void serializeTo(char* buffer);
	
};

#endif /*INTVALUE_H_*/
