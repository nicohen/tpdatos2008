#ifndef STRUCTURETYPE_H_
#define STRUCTURETYPE_H_

#include <vector>
#include "DataType.h"

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
	
};

#endif /*STRUCTURETYPE_H_*/
