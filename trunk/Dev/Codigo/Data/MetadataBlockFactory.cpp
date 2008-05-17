#include "MetadataBlockFactory.h"
#include "MetadataBlock.h"


MetadataBlockFactory::MetadataBlockFactory()
{
}

MetadataBlockFactory::~MetadataBlockFactory()
{
}

Block* MetadataBlockFactory::createBlock(char* content, T_BLOCKSIZE size){
	return new MetadataBlock(content,size);
}

Block* MetadataBlockFactory::createEmptyBlock(T_BLOCKSIZE size){
	return new MetadataBlock(size);
}
