#ifndef DATAVALUE_H_
#define DATAVALUE_H_

#include "DataType.h"
#include <string>

using namespace std;

class DataType;
typedef unsigned short T_STRING_LENGHT;
class DataValue
{
	
protected:
	virtual T_STRING_LENGHT getSerializationSize()=0;
	virtual void serializeTo(char* buffer)=0;	
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght)=0;
public:
	DataValue();
	virtual ~DataValue();
	
	//otros
	virtual bool isInstanceOf(DataType* dType)=0;
	virtual bool equals(DataValue* other);
	virtual void toString(string* buffer)=0;
	virtual char getCharType()=0;
	T_STRING_LENGHT getSerializationFullSize();
	char* serialize();	
	char* deserialize(char* data);//Esto va en la clase madre (no es virtual)
	virtual DataValue* clone()=0;
	virtual bool isNull();
};

#endif /*DATAVALUE_H_*/
