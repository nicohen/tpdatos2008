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
protected:
	virtual T_STRING_LENGHT getSerializationSize();
	virtual void serializeTo(char* buffer);	
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght);
	
public:
	StringValue(char* value);
	virtual ~StringValue();
	
	//otros
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual void toString(string* buffer);
	virtual char* getString();
};


#endif /*STRINGVALUE_H_*/
