#include "StructureValue.h"
#include "StructureType.h"
#include "IntValue.h"

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

DataType* StructureValue::getType(){
	StructureType* vvType=NULL;
	vvType=new StructureType();
	vector<DataValue*>::iterator iter;
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		vvType->addType(((DataValue*)*iter)->getType());
	}
	return vvType;
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

bool StructureValue::equals(DataValue* other){
	StructureValue* otherStructure=NULL;
	
	DataValue* each=NULL;
	DataValue* eachOther=NULL;
	
	vector<DataValue*>::iterator ownIter;
	vector<DataValue*>::iterator otherIter;
	
	otherStructure=(StructureValue*) other;
	if(DataValue::equals(other)){
		if(this->getCount()!=otherStructure->getCount()){
			printf("\nFINAL 1 \n");
			return false;
		}
		for (ownIter = this->_dataValues->begin(),otherIter = otherStructure->_dataValues->begin();
			ownIter != this->_dataValues->end();
			ownIter++,otherIter++)
		{
			each=((DataValue*)*ownIter);
			eachOther=((DataValue*)*otherIter);
			if(!each->equals(eachOther)){
				printf("\nFINAL 2 \n");
				return false;	
			}			
		}
		printf("\nFINAL 3 \n");
		return true;
	}else{
		printf("\nFINAL 4 \n");
		return false;	
	}	
}

T_STRING_LENGHT StructureValue::getSerializationSize(){
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	T_STRING_LENGHT size;
	size=0;
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		each=((DataValue*)*iter);
		size+=each->getSerializationFullSize();
	}
	return size;
}

void StructureValue::serializeTo(char* buffer){
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	char* eachSerialization=NULL;
	char* currentBufferLocation=NULL;
	currentBufferLocation=buffer;
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		each=((DataValue*)*iter);
		eachSerialization=each->serialize();		
		memcpy(currentBufferLocation,eachSerialization,each->getSerializationFullSize());
		currentBufferLocation+=each->getSerializationFullSize();
		free(eachSerialization);
	}
}	
void StructureValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	//Recorrer los valores y llamar al deserialize de cada fucking eachhhh
	this->addValue(new IntValue(10));//Borrar el include
	DataValue* each=NULL;
	vector<DataValue*>::iterator iter;
	for (iter = this->_dataValues->begin(); iter != this->_dataValues->end(); iter++ )
	{
		each=((DataValue*)*iter);
		//((IntValue*)each)
	}
}

