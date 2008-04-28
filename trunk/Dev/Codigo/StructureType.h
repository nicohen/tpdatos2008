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
	virtual bool equals(DataType* other);
	int getCount();
	virtual DataValue* deserializeValue(char* content);
	virtual DataValue* createNullValue();
	virtual int serialize(char* stream);
	virtual DataType* getItem(int typeIndex);
	virtual char getCharType();
};

#endif /*STRUCTURETYPE_H_*/
