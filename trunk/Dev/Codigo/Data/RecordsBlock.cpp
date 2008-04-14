#include "RecordsBlock.h"
#include "../Utils.h"

using namespace std;




RecordsBlock::RecordsBlock(T_BLOCKSIZE size):Block(size){
	this->_records=new vector<RawRecord*>();
}
RecordsBlock::RecordsBlock(char* content,T_BLOCKSIZE size):Block(content,size){
	this->_records=new vector<RawRecord*>();
	this->deserializeRecords();
}

void RecordsBlock::deserializeRecords(){
	T_BLOCKSIZE recordsCount;
	T_BLOCKSIZE i;
	T_BLOCKSIZE offset=0;
	RawRecord* record;
	memcpy(&recordsCount,Block::getContent()+offset,sizeof(T_BLOCKSIZE));
	offset+=sizeof(T_BLOCKSIZE);
	for (i = 0; i < recordsCount; ++i) {
		record=this->deserializeRecord(Block::getContent(),offset);
		this->_records->push_back(record);
		offset+=this->getSerializationSize(record);
	}	
}

RawRecord* RecordsBlock::deserializeRecord(char* data, T_BLOCKSIZE offset){
	T_BLOCKSIZE recSize;
	RawRecord* res;
	char* rec1content;
	memcpy(&recSize,Block::getContent()+offset,sizeof(T_BLOCKSIZE));
	rec1content=(char*)malloc(recSize);
	memcpy(rec1content,Block::getContent()+offset+sizeof(T_BLOCKSIZE),recSize);
	res=new RawRecord(rec1content,recSize);
	free(rec1content);
	return res;
}



RecordsBlock::~RecordsBlock(void)
{
	vector<RawRecord*>::iterator iter;
	for (iter = this->_records->begin(); iter != this->_records->end(); iter++ )
	{
		delete ((RawRecord*)*iter);
	}
	this->_records->clear();
	delete this->_records;
}



T_BLOCKSIZE RecordsBlock::getFreeSpace(){
	T_BLOCKSIZE usedSpace=0;
	RawRecord* each;
	vector<RawRecord*>::iterator iter;
	for (iter = this->_records->begin(); iter != this->_records->end(); iter++ )
	{
		each=(RawRecord*)*iter;
		usedSpace+=this->getSerializationSize(each);
	}
	return this->getSize()-usedSpace;
}


void RecordsBlock::writeAllRecords(){
	vector<RawRecord*>::iterator iter;
	RawRecord* each;
	T_BLOCKSIZE offset=0;
	T_BLOCKSIZE recordsCount=0;
	recordsCount=this->_records->size();
	this->setFragment((char*)&recordsCount,0,sizeof(T_BLOCKSIZE));
	offset+=sizeof(T_BLOCKSIZE);
	for (iter = this->_records->begin(); iter != this->_records->end(); iter++ )
	{	
		each=(RawRecord*)*iter;
		this->writeOnBlock(each,this,offset);
		offset+=this->getSerializationSize(each);
	}	
}

void RecordsBlock::writeOnBlock(RawRecord* record,Block* block,T_BLOCKSIZE offset){
	T_BLOCKSIZE recordSize;
	recordSize=record->getSize();
	block->setFragment((char*)&recordSize,offset,sizeof(T_BLOCKSIZE));
	block->setFragment(record->getContent(),offset+sizeof(T_BLOCKSIZE),recordSize);
}

T_BLOCKSIZE RecordsBlock::getSerializationSize(RawRecord* record){
	return sizeof(T_BLOCKSIZE)+record->getSize();
}

void RecordsBlock::appendRecord(RawRecord* record){
	this->_records->push_back(record);
}

char* RecordsBlock::getContent(){
	this->writeAllRecords();
	return Block::getContent();
}

vector<RawRecord*>* RecordsBlock::getRecords(){
	return this->_records;
}
