#include "Record.h"
#include "../IntValue.h"
#include "../StructureValue.h"
#include "../IntValue.h"

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

void Record::deserialize(RawRecord* data,vector<Field*>* recordFields){
	vector<Field*>::iterator iter;
	Field* each=NULL;
	DataValue* currentValue=NULL;
	char* currentDataPointer=data->getContent();
	for (iter = recordFields->begin(); iter != recordFields->end(); iter++ )
	{
		each=((Field*)*iter);
		currentValue=each->getDataType()->deserializeValue(currentDataPointer);
		this->addValue(currentValue);
		currentDataPointer+=currentValue->getSerializationFullSize();
	}
}

//Calcular recordSize
//Serializar
RawRecord* Record::serialize(){
	char* data=NULL;
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	char* eachSerialization=NULL;
	char* currentBufferLocation=NULL;
	T_BLOCKSIZE recordSize=0;
	
	recordSize=this->getSerializationFullSize();
	data=(char*)malloc(recordSize);
	currentBufferLocation=data;
	for (iter = this->_values->begin(); iter != this->_values->end(); iter++ )
	{
		each=((DataValue*)*iter);
		eachSerialization=each->serialize();		
		memcpy(currentBufferLocation,eachSerialization,each->getSerializationFullSize());
		currentBufferLocation+=each->getSerializationFullSize();
		free(eachSerialization);
	}
	return new RawRecord(data,recordSize);
}

T_BLOCKSIZE Record::getSerializationFullSize(){
	T_BLOCKSIZE res=0;
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	//SUMAR PRIMERO EL TMAÑO DEL TIPO DE DATO
	res+=sizeof(T_RECORD_SIZE);
	for (iter = _values->begin(); iter != _values->end(); iter++ ) {
		each=((DataValue*)*iter);
		res+=each->getSerializationFullSize();
	}
	return res;
}

bool Record::equals(Record* other){
	//DataValue* each=NULL;
	return StructureValue::equalsValueVectors(this->_values,other->_values);
}

void Record::toString(string* buffer) {
	DataValue* each;	
	bool firstValue = true;
	
	buffer->append("[");
	vector<DataValue*>::iterator iter;
	for (iter = _values->begin(); iter != _values->end(); iter++ ) {
		each = ((DataValue*)*iter);
		if (firstValue)
			firstValue = false;
		else
			buffer->append(",");
		each->toString(buffer);
	}
	buffer->append("]");
}

bool Record::matchField(T_BLOCKSIZE fieldNumber,Record* other){
	DataValue* myValue=NULL;
	DataValue* otherValue=NULL;
	if(fieldNumber>=0 && fieldNumber< this->_values->size()){
		myValue=(DataValue*)this->_values->at(fieldNumber);
	}else{
		return false;
	}
	
	if(fieldNumber>=0 && fieldNumber< other->_values->size()){
		otherValue=(DataValue*)other->_values->at(fieldNumber);
	}else{
		return false;
	}
	return myValue->equals(otherValue);
}

