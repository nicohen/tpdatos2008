#include "RecordsBlock.h"
#include "../Utils.h"

using namespace std;

RecordsBlock::RecordsBlock(T_BLOCKSIZE size):Block(size){
	this->_records=new vector<RawRecord*>();
}
RecordsBlock::RecordsBlock(char* content,T_BLOCKSIZE size):Block(content,size){
	this->_records=new vector<RawRecord*>();
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
	return 0;
}

void RecordsBlock::writeAllRecords(){
	vector<RawRecord*>::iterator iter;
	RawRecord* irec;
	T_BLOCKSIZE offset=0;
	
	for (iter = this->_records->begin(); iter != this->_records->end(); iter++ )
	{	
		irec=(RawRecord*)*iter;
		this->writeRecord(irec->getContent(),irec->getSize(),offset);
		offset+=sizeof(T_BLOCKSIZE)+irec->getSize();
	}	
}

void RecordsBlock::writeRecord(char* content, T_BLOCKSIZE recordSize,T_BLOCKSIZE offset){
	this->setFragment((char*)&recordSize,offset,sizeof(T_BLOCKSIZE));
	this->setFragment(content,offset+sizeof(T_BLOCKSIZE),recordSize);
}

void RecordsBlock::appendRecord(char* content,T_BLOCKSIZE recordSize){
	RawRecord* newRecord;
	newRecord=new RawRecord(content,recordSize);
	this->_records->push_back(newRecord);
}

char* RecordsBlock::getContent(){
	this->writeAllRecords();
	return Block::getContent();
}
