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
	
	void addType(DataType* aType);
	
	virtual bool isInstanceOf(void* anObject);
	virtual ~StructureType();
};

#endif /*STRUCTURETYPE_H_*/
