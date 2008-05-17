#ifndef RECORDSBLOCKFACTORY_H_
#define RECORDSBLOCKFACTORY_H_

#include "BlockFactory.h"

class RecordsBlockFactory : public BlockFactory
{
public:
	RecordsBlockFactory();
	virtual ~RecordsBlockFactory();
	virtual Block* createBlock(char* content, T_BLOCKSIZE size);
};

#endif /*RECORDSBLOCKFACTORY_H_*/
