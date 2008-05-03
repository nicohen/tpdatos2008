#ifndef BLOCKSBUFFER_H_
#define BLOCKSBUFFER_H_

#include "string.h"
#include "BufferKey.h"
#include <map>
#include "ReplacementSelector.h"
#include "../Data/Block.h"
#include "../DataFile.h"
#include "SystemBuffer.h"

class  BlocksBuffer{
	private:
		SystemBuffer _systemBuffer;		

	public:
		BlocksBuffer(int size);
		void addBlock(char* fileName, int blockNumber, Block* block);
		Block* getBlock(char* fileName, int blockNumber);
		bool isInBuffer(char* fileName, int blockNumber);
		unsigned int getHits();
		unsigned int getMiss();
		unsigned int getTotalSize();
		unsigned int getCurrentSize();
		unsigned int getBlocksCount();
		virtual ~BlocksBuffer();
};


#endif /*BLOCKSBUFFER_H_*/
