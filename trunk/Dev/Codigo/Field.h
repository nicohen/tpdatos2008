#ifndef FIELD_H_
#define FIELD_H_

#include "DataType.h"
class Field
{
public:
	Field();
	
	bool isMandatory();
	bool isPolyvalent();
	DataType* getType();
	virtual ~Field();
};

#endif /*FIELD_H_*/
