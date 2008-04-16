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
protected:
	virtual T_STRING_LENGHT getSerializationSize();
	virtual void serializeTo(char* buffer);	
	virtual void deserializeValue(char* data,T_STRING_LENGHT dataLenght);
public:
	StructureValue();
	virtual ~StructureValue();
	
	virtual bool equals(DataValue* other);
	virtual DataType* getType();
	virtual void toString(string* buffer);
	void addValue(DataValue* aType);
	int getCount();
};

#endif /*STRUCTUREVALUE_H_*/
