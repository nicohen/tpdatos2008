#ifndef BUFFERKEY_H_
#define BUFFERKEY_H_

#include "IComparable.h"
#include "string.h"
#include <sstream>

class BufferKey:public IComparable{
	private:
		char* _fileName;
		int _blockNumber;
public:
	BufferKey(char* fileName, int block);
	char* getFileName(void);
	int getBlockNumber(void);
	virtual ~BufferKey();
	bool isLowerThan(IComparable* other);
	char* toString();
};

#endif /*BUFFERKEY_H_*/
