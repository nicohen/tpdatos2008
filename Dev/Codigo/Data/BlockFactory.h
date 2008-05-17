#ifndef BLOCKFACTORY_H_
#define BLOCKFACTORY_H_

#include "Block.h"

class BlockFactory
{
public:
	BlockFactory();
	virtual ~BlockFactory();
	virtual Block* createBlock(char* content, T_BLOCKSIZE size);
};

#endif /*BLOCKFACTORY_H_*/
