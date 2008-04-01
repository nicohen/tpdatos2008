#ifndef STRUCTUREVALUE_H_
#define STRUCTUREVALUE_H_

#include "DataValue.h"
#include "StructureType.h"

class StructureValue:public DataValue
{	
private:
	vector<DataValue*>* _dataValues;
	void clear();
public:
	StructureValue();
	virtual ~StructureValue();
	
	virtual DataType* getType();
	virtual char* toString();
	
	void addValue(DataValue* aType);
};

#endif /*STRUCTUREVALUE_H_*/
