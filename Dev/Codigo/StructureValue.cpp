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

bool StructureValue::equals(DataValue* other){
	return false;
}

char* StructureValue::serialize(){
	return NULL;
}

