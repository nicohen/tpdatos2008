#ifndef SYSTEMBUFFER_H_
#define SYSTEMBUFFER_H_

#include "string.h"
#include "BufferKey.h"
#include "map.h"
#include "ReplacementSelector.h"
#include "../Data/Block.h"
#include "../DataFile.h"

struct bufferKeyCmp {
	bool operator()( BufferKey* key1, BufferKey* key2 ) const {
		key1->isLowerThan(key2);
	}
};

class SystemBuffer{
	private:
		map<BufferKey*, Block*, bufferKeyCmp> _buffer;
		unsigned int _bufferSize;
		unsigned int _bufferCurrentSize;
		ReplacementSelector replacementCriteria;
		
		void removeElement(BufferKey* bk);
		void makeSpace(int elementSize);
	public:
		SystemBuffer(int size);
		void addBlock(DataFile* file, int blockNumber, Block* block);
		Block* getBlock(DataFile* file, int blockNumber);
		bool isInBuffer(DataFile* file, int blockNumber);
		virtual ~SystemBuffer();
};

#endif /*SYSTEMBUFFER_H_*/
