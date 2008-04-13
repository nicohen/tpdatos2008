#ifndef RecordsBlock_H_
#define RecordsBlock_H_

#include "Block.h"

class RecordsBlock: public Block
{
private:
public:
	
	RecordsBlock(T_BLOCKSIZE size);
	RecordsBlock(char* content,T_BLOCKSIZE size);
	virtual ~RecordsBlock(void);

	void appendRecord(char* content,T_BLOCKSIZE recordSize);
	
	char* moveFirst();
	char* moveNext();
	char* getCurrent();
	bool hasNext();
	void deleteCurrent();
	virtual T_BLOCKSIZE getFreeSpace();

};

#endif /*RecordsBlock_H_*/
