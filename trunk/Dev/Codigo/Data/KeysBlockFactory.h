#ifndef KEYSBLOCKFACTORY_H_
#define KEYSBLOCKFACTORY_H_

#include "BlockFactory.h"

class KeysBlockFactory : public BlockFactory
{
public:
	KeysBlockFactory();
	virtual ~KeysBlockFactory();
	virtual Block* createBlock(char* content, T_BLOCKSIZE size);
	virtual Block* createEmptyBlock(T_BLOCKSIZE size);
};

#endif /*KEYSBLOCKFACTORY_H_*/
