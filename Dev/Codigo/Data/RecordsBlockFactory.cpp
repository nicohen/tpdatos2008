#include "RecordsBlockFactory.h"
#include "RecordsBlock.h"

RecordsBlockFactory::RecordsBlockFactory()
{
}

RecordsBlockFactory::~RecordsBlockFactory()
{
}


Block* RecordsBlockFactory::createBlock(char* content, T_BLOCKSIZE size){
	return new RecordsBlock(content,size);
}
