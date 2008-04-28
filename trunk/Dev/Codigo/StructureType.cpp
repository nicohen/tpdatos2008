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
	if (this->getCharType()!=other->getCharType()){
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

DataValue* StructureType::deserializeValue(char* content){
	DataValue* res=NULL;
	res=this->createNullValue();
	res->deserialize(content);
	return res;
}

DataValue* StructureType::createNullValue(){
	return new StructureValue();
}


int StructureType::serialize(char* stream){
	int counter=0;
	char type= DataType::STRUCTURED_TYPE;
	memcpy(stream,(char*)&type,sizeof(char));
	counter+=sizeof(char);
	vector<DataType*>::iterator iterador;
	unsigned short length= _dataTypes->size();
	memcpy(stream+counter,(char*)&length,sizeof(short));
	counter+=sizeof(short);
	DataType* each;
	for (iterador = this->_dataTypes->begin(); iterador != this->_dataTypes->end(); iterador++ ){	
		each=(DataType*)*iterador;
		counter+=each->serialize(stream+counter);
	}
	return counter;
}

DataType* StructureType::getItem(int typeIndex){
	return this->_dataTypes->at(typeIndex);
}

char StructureType::getCharType(){
	return DataType::STRUCTURED_TYPE;
};