#ifndef STRINGVALUE_H_
#define STRINGVALUE_H_

#include "DataValue.h"
#include "Utils.h"
#include "StringType.h"
#include <string>

 
using namespace std;
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
	virtual void toString(string* buffer);
	virtual char* getString();
	virtual char* serialize();
	
	void deserialize(char* data);//Esto va en la clase madre (no es virtual)
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght);
	virtual T_STRING_LENGHT getSerializationSize();
	virtual void serializeTo(char* buffer);
};


#endif /*STRINGVALUE_H_*/
