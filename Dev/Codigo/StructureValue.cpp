#include "StructureValue.h"
#include "StructureType.h"

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
	
}
void StructureValue::serializeTo(char* buffer){
	
}	
void StructureValue::deserializeValue(char* data,T_STRING_LENGHT dataLenght){
	
}

