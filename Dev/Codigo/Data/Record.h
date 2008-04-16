#ifndef RECORD_H_
#define RECORD_H_

#include "RawRecord.h"
#include "../DataValue.h"
#include <vector>
#include "string.h"
#include "../Field.h"

using namespace std;
/*
 * Contiene los datos de un registro
 * */
typedef unsigned short T_RECORD_SIZE; 

class Record
{
private:
	void clearValues(vector<DataValue*>* values);
	vector<DataValue*>* _values;
public:
	Record();
	virtual ~Record();
	//Getters
	vector<DataValue*>* getValues();
	void toString(string* buffer);
	
	//Otros metodos
	void addValue(DataValue* aValue);
	void addValues(vector<DataValue*>* valueList);
	
	RawRecord* serialize();	
	void deserialize(RawRecord* data,vector<Field*>* recordFields);
	bool equals(Record* other);
	T_BLOCKSIZE getSerializationFullSize();
};
#endif /*RECORD_H_*/
