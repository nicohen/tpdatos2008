#ifndef DATAVALUE_H_
#define DATAVALUE_H_

#include "DataType.h"

class DataValue
{
public:
	DataValue();
	virtual ~DataValue();
	
	//otros
	virtual bool equals(DataValue* other)=0;
	virtual char* toString()=0;
	virtual DataType* getType()=0;
};

#endif /*DATAVALUE_H_*/
