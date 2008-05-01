#ifndef BLOCKSBUFFER_H_
#define BLOCKSBUFFER_H_

#include "string.h"
#include "BufferKey.h"
#include "map.h"
#include "ReplacementSelector.h"
#include "../Data/Block.h"
#include "../DataFile.h"
#include "SystemBuffer.h"

class  BlocksBuffer{
	private:
		SystemBuffer _systemBuffer;		

	public:
		BlocksBuffer(int size);
		void addBlock(DataFile* file, int blockNumber, Block* block);
		Block* getBlock(DataFile* file, int blockNumber);
		bool isInBuffer(DataFile* file, int blockNumber);
		virtual ~BlocksBuffer();
};


#endif /*BLOCKSBUFFER_H_*/
