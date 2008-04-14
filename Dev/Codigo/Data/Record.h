#ifndef RECORD_H_
#define RECORD_H_

#include "RawRecord.h"
#include "../DataValue.h"
#include <vector>
using namespace std;
/*
 * Contiene los datos de un registro
 * */
class Record
{
private:
	void clearValues(vector<DataValue*>* values);
	vector<DataValue*>* _values;
public:
	Record();
	virtual ~Record();
	char* toString();
	//Getters
	vector<DataValue*>* getValues();
	
	//Otros metodos
	void addValue(DataValue* aValue);
	void addValues(vector<DataValue*>* valueList);
	RawRecord* serialize();
};
#endif /*RECORD_H_*/
