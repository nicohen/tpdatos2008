#ifndef METADATABLOCKFACTORY_H_
#define METADATABLOCKFACTORY_H_

#include "BlockFactory.h"

class MetadataBlockFactory : public BlockFactory
{
public:
	MetadataBlockFactory();
	virtual ~MetadataBlockFactory();
	virtual Block* createBlock(char* content, T_BLOCKSIZE size);
};

#endif /*METADATABLOCKFACTORY_H_*/
