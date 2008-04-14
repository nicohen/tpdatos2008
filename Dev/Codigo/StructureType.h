#ifndef STRUCTURETYPE_H_
#define STRUCTURETYPE_H_

#include <vector>
#include "DataType.h"

#include "StructureValue.h"


using namespace std;

class StructureType:public DataType
{
private:
	vector<DataType*>* _dataTypes;
public:
	StructureType();
	virtual ~StructureType();
	
	//Otros
	void addType(DataType* aType);
	virtual bool isInstanceOf(void* anObject);
	virtual bool equals(DataType* other);
	virtual int getUniqueIdentifier();
	int getCount();
	virtual DataValue* deserializeValue(char* content);	
};

#endif /*STRUCTURETYPE_H_*/
