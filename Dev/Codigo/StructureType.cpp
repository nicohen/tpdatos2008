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
