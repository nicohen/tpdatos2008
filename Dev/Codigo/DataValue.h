#ifndef DATAVALUE_H_
#define DATAVALUE_H_

#include "DataType.h"
 
class DataType;

class DataValue
{
public:
	DataValue();
	virtual ~DataValue();
	
	//otros
	virtual bool equals(DataValue* other)=0;
	virtual DataType* getType()=0;
	virtual char* serialize()=0;
};

#endif /*DATAVALUE_H_*/
