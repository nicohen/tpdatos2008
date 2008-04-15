#ifndef STRUCTUREVALUE_H_
#define STRUCTUREVALUE_H_

#include <vector>

#include "DataValue.h"


using namespace std;
class StructureValue:public DataValue
{	
private:
	vector<DataValue*>* _dataValues;
	void clear();
public:
	StructureValue();
	virtual ~StructureValue();
	
	virtual bool equals(DataValue* other);
	virtual DataType* getType();	
	void addValue(DataValue* aType);	
	virtual char* serialize();	
};

#endif /*STRUCTUREVALUE_H_*/
