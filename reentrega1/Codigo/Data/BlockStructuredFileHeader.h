#ifndef BLOCKSTRUCTUREDFILEHEADER_H_
#define BLOCKSTRUCTUREDFILEHEADER_H_

#include "Block.h"
#include <stdlib.h>
#include <stdio.h>

class BlockStructuredFileHeader
{	
private:
	T_BLOCKSIZE _blockSize;	
	T_BLOCKCOUNT _blockCount;
		
	char* getBlockSizePosition(char* reference);
	char* getBlockCountPosition(char* reference);
	char* getFirstFreeSpaceListItem(char* reference);
public:	
	
	T_BLOCKSIZE getBlockSize();
	T_BLOCKCOUNT getBlockCount();
	void setBlockSize(T_BLOCKSIZE size);
	void setBlockCount(T_BLOCKCOUNT count);
	
	void loadPropertiesFromBuffer(char* buffer);
	void saveHeaderToBuffer(char* buffer);
	
	BlockStructuredFileHeader();
	virtual ~BlockStructuredFileHeader();
};

#endif /*BLOCKSTRUCTUREDFILEHEADER_H_*/
