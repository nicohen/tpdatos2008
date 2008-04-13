#include "RecordsBlock.h"

RecordsBlock::RecordsBlock(T_BLOCKSIZE size):Block(size){
	
}
RecordsBlock::RecordsBlock(char* content,T_BLOCKSIZE size):Block(content,size){
	
}

RecordsBlock::~RecordsBlock(void)
{
}
T_BLOCKSIZE RecordsBlock::getFreeSpace(){
	
}

void RecordsBlock::appendRecord(char* content,T_BLOCKSIZE recordSize){
	
}
