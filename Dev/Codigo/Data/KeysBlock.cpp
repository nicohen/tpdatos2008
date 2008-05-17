#include "KeysBlock.h"
#include "Record.h"

Block* KeysBlock::createKeysBlock(char* content, T_BLOCKSIZE size){
	return new KeysBlock(content,size);
	//no hacer nada
}

void KeysBlock::loadDispersionField(){
	_fieldList=new vector<Field*>();
	Field* intField = new Field();
	intField->setDataType(new IntType());
	intField->setIsMandatory(true);
	intField->setIsPolyvalent(false);
	_fieldList->push_back(intField);	
}
 
KeysBlock::KeysBlock(T_BLOCKSIZE size,int dispersion):RecordsBlock(size){
	//agregar el registro que tienen la dispersion
	this->loadDispersionField();
	Record* dispersionRecord=new Record();
	dispersionRecord->addValue(new IntValue(dispersion));
	this->push_back(dispersionRecord->serialize());
}

int KeysBlock::getDispersion(){ 
	RawRecord* recordData= this->getRecords()->at(0);
	Record* dispersionRecord =new Record();
	dispersionRecord->deserialize(recordData,_fieldList);
	IntValue* intvalue = (IntValue*)*dispersionRecord->getValues()->begin();
	delete recordData;
	return intvalue->getInt();
}

void KeysBlock::setDispersion(int dispersion){
	Record* dispersionRecord =new Record();
	dispersionRecord->addValue(new IntValue(dispersion));
	
	this->getRecords()->erase(this->getRecords()->begin());
	this->getRecords()->insert(this->getRecords()->begin(),dispersionRecord->serialize());
	delete dispersionRecord;
}

KeysBlock::KeysBlock(char* content,T_BLOCKSIZE size):RecordsBlock(content,size){
	this->loadDispersionField();
	//No hace nada porque el registro de dispersion ya lo tiene
}

KeysBlock::~KeysBlock()
{
	delete _fieldList;
}

vector<RawRecord*>::iterator KeysBlock::begin(){
	//CUIDADO: hay que devolver el segundo elemento
	return RecordsBlock::begin()+1;
}

vector<RawRecord*>::iterator KeysBlock::end(){
	return RecordsBlock::end();
}

void KeysBlock::erase(vector<RawRecord*>::iterator it){
	return RecordsBlock::erase(it);
}

T_BLOCKSIZE KeysBlock::RecordCount(){
	//Descontar el elemento uno
	return (RecordsBlock::RecordCount()-1);
}

RawRecord* KeysBlock::at(T_BLOCKSIZE i){
	return RecordsBlock::at(i-1);	
}

void KeysBlock::clear(){
	int dispersion=this->getDispersion();
	RecordsBlock::clear();
	this->setDispersion(dispersion);
}