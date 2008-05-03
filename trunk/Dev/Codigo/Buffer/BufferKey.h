#ifndef BUFFERKEY_H_
#define BUFFERKEY_H_

#include "IComparable.h"

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
	virtual char* toString();
};

#endif /*BUFFERKEY_H_*/
