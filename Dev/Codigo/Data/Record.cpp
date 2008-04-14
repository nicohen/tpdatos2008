#include "Record.h"
using namespace std;
Record::Record()
{
	_values=new vector<DataValue*>();
}

Record::~Record()
{
	clearValues(_values);
	delete _values;
}

vector<DataValue*>* Record::getValues(){
	//Usa el constructor de copia de la clase vector
	return new vector<DataValue*>(*_values);
}

void Record::addValue(DataValue* aValue){
	_values->push_back(aValue);
}

void Record::addValues(std::vector<DataValue*>* valueList){
	vector<DataValue*>::iterator iter;
	for (iter = valueList->begin(); iter != valueList->end(); iter++ ){
		_values->push_back(*iter);
	}
	delete valueList;
}

void Record::clearValues(vector<DataValue*>* values){
	vector<DataValue*>::iterator iter;
	for (iter = _values->begin(); iter != _values->end(); iter++ ) {
		delete ((DataValue*)*iter);
	}
	values->clear();
}

void deserialize(RawRecord* data){
	
}
