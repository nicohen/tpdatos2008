#include "BlockFactory.h"

BlockFactory::BlockFactory()
{
}

BlockFactory::~BlockFactory()
{
}

Block* BlockFactory::createBlock(char* content, T_BLOCKSIZE size){
	return new Block(content,size);
}

Block* BlockFactory::createEmptyBlock(T_BLOCKSIZE size){
	return new Block(size);
}
