#include "StructureValue.h"
#include "StructureType.h"
#include "IntValue.h"
#include "Data/Record.h"
#include "DataType.h"

using namespace std;

StructureValue::StructureValue()
{
	this->_dataValues = new vector<DataValue*>();
}

StructureValue::~StructureValue()
{
	this->clear();
	delete(this->_dataValues);
}

char StructureValue::getCharType(){
	return DataType::STRUCTURED_TYPE;
}

void StructureValue::toString(string* buffer){
	DataValue* each;
	bool firstValue=true;
	
	vector<DataValue*>::iterator iter;
	buffer->append("|");
	for(iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++) {
		each = (DataValue*)*iter;
		if(firstValue)
			firstValue=false;
		else
			buffer->append(",");
		each->toString(buffer);
	}
	buffer->append("|");
}

void StructureValue::addValue(DataValue* aType){
	this->_dataValues->push_back(aType);
}

void StructureValue::clear(){
	vector<DataValue*>::iterator iter;
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		delete ((DataValue*)*iter);
	}
	this->_dataValues->clear();
}

int StructureValue::getCount(){
	return this->_dataValues->size();
}

bool StructureValue::equalsValueVectors(vector<DataValue*>* vec1,vector<DataValue*>* vec2){
	DataValue* each=NULL;
	DataValue* eachOther=NULL;
	
	vector<DataValue*>::iterator ownIter;
	vector<DataValue*>::iterator otherIter;
	
	if(vec1->size()!=vec2->size()){
		//printf("\nFINAL 1 \n");
		return false;
	}
	for (ownIter = vec1->begin(),otherIter = vec2->begin();
		ownIter != vec1->end();
		ownIter++,otherIter++)
	{
		each=((DataValue*)*ownIter);
		eachOther=((DataValue*)*otherIter);
		if(!each->equals(eachOther)){
			//printf("\nFINAL 2 \n");
			return false;	
		}			
	}
	//printf("\nFINAL 3 \n");
	return true;
}

bool StructureValue::equals(DataValue* other){
	StructureValue* otherStructure=NULL;
	
	vector<DataValue*>::iterator ownIter;
	vector<DataValue*>::iterator otherIter;
	
	otherStructure=(StructureValue*) other;
	if(DataValue::equals(other)){
		return equalsValueVectors(this->_dataValues,otherStructure->_dataValues);
	}else{
//		printf("\nFINAL 4 \n");
		return false;	
	}	
}

T_STRING_LENGHT StructureValue::getSerializationSize(){
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	T_RECORD_SIZE size;
	size=0;
	size+=sizeof(T_RECORD_SIZE);
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		each=((DataValue*)*iter);
		size+=each->getSerializationFullSize()
		+1;//le sumo un espacio para guardar el tipo
	}
	return size;
}

void StructureValue::serializeTo(char* buffer){
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	char* eachSerialization=NULL;
	char* currentBufferLocation=NULL;
	currentBufferLocation=buffer;
	T_RECORD_SIZE valueCount;
	
	valueCount=this->getCount();
	
	//Serializo la cantidad de elementos
	memcpy(currentBufferLocation,(char*)&valueCount,sizeof(T_RECORD_SIZE));
	currentBufferLocation+=sizeof(T_RECORD_SIZE);
	
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		each=((DataValue*)*iter);
		
		//Serializo el tipo del dataValue
		*currentBufferLocation=each->getCharType();
		currentBufferLocation+=1;
		
		//Serializo el contenido del dataValue
		eachSerialization=each->serialize();
		memcpy(currentBufferLocation,eachSerialization,each->getSerializationFullSize());
		currentBufferLocation+=each->getSerializationFullSize();
		free(eachSerialization);
	}
}	
void StructureValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	char* currentDataPointer;
	T_RECORD_SIZE valueCount;
	T_RECORD_SIZE i;
	DataValue* desderializedValue;
	DataType* currentValueType;	
	currentDataPointer=data;
	memcpy(&valueCount,currentDataPointer,sizeof(T_RECORD_SIZE));
	currentDataPointer+=sizeof(T_RECORD_SIZE);
	
	for (i = 0; i < valueCount; ++i) {
		//deserializo el tipo 
		currentValueType=DataType::createType(*currentDataPointer);
		currentDataPointer+=1;
			
		//deserializo el valor
		desderializedValue=currentValueType->createNullValue();
		currentDataPointer=desderializedValue->deserialize(currentDataPointer);
		this->addValue(desderializedValue);
		delete currentValueType;
	}	
}


bool StructureValue::isInstanceOf(DataType* dType){
	StructureType* type=NULL;
	int valueIndex=0;
	int typeIndex=0;
	if(dType->getCharType()!=DataType::STRUCTURED_TYPE){
		return false;
	}
	type=(StructureType*) dType;
	
	//Un structureValue sin elementos se considera como nulo de cualquier structureType
	if(this->getCount()==0){
		return true;
	}
	if(type->getCount()==0){
		return false;
	}
	for (valueIndex = 0; valueIndex < this->_dataValues->size(); ++valueIndex) {
		if(! ((DataValue*)this->_dataValues->at(valueIndex))->isInstanceOf(type->getItem(typeIndex))){
			return false;
		}		
		if(++typeIndex>=type->getCount()){
			typeIndex=0;
		}
	}
	return true;
}

bool StructureValue::isNull(){
	return this->getCount()==0;
}