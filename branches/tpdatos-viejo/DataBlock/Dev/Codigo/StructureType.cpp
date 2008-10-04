#include "StructureType.h"

StructureType::StructureType()
{
	this->_dataTypes = new vector<DataType*>();
}

void clearDataTypes(vector<DataType*>* dataTypes){
	vector<DataType*>::iterator iter;
	for (iter = dataTypes->begin(); iter != dataTypes->end(); iter++ )
	{
		delete ((DataType*)*iter);
	}
	dataTypes->clear();
}

StructureType::~StructureType()
{
	clearDataTypes(this->_dataTypes);
	delete(this->_dataTypes);
}

void StructureType::addType(DataType* aType){
	this->_dataTypes->push_back(aType);
}

int StructureType::getCount(){
	return this->_dataTypes->size();
}

bool StructureType::equals(DataType* other){
	if (this->getUniqueIdentifier()!=other->getUniqueIdentifier()){
		return false;
	}else{
		StructureType* otherStructureType=(StructureType*)other;
		if(otherStructureType->getCount()!=this->getCount()){
			return false;
		}else{
			vector<DataType*>::iterator iter1;
			vector<DataType*>::iterator iter2;
			for (iter1 = this->_dataTypes->begin(),iter2 = otherStructureType->_dataTypes->begin(); iter1 != this->_dataTypes->end(); iter1++,iter2++ )
			{
				DataType* type1 = ((DataType*)*iter1);
				DataType* type2 = ((DataType*)*iter2);
				if(!(type1->equals(type2))){
					return false;
				}
			}
			return true;
		}
	}
}

int StructureType::getUniqueIdentifier(){
	return 3;
}

bool StructureType::isInstanceOf(void* anObject){
	/*
	//verificar que anObject se pueda convertir en vector, recorrerlo y validar
	vector<DataType*>::iterator iter;
	for (iter = this->_dataTypes->begin(); iter != this->_dataTypes->end(); iter++ )
	{
		if(((DataType*)*iter)->isInstanceOf(anObject)==false){
			return false;
		}
	}
	*/
	return false;
}
