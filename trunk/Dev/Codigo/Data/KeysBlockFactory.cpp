#include "KeysBlockFactory.h"
#include "KeysBlock.h"

KeysBlockFactory::KeysBlockFactory()
{
}

KeysBlockFactory::~KeysBlockFactory()
{
}

Block* KeysBlockFactory::createBlock(char* content, T_BLOCKSIZE size){
	return new KeysBlock(content,size);
} 

Block* KeysBlockFactory::createEmptyBlock(T_BLOCKSIZE size){
	return new KeysBlock(size,1);
}
