#ifndef STRUCTUREVALUE_H_
#define STRUCTUREVALUE_H_

#include <vector>
#include "DataValue.h"
#include <string>

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
	virtual void toString(string* buffer);
	virtual char* serialize();	
	void addValue(DataValue* aType);
};

#endif /*STRUCTUREVALUE_H_*/
