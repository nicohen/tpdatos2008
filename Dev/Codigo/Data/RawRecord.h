#ifndef RAWRECORD_H_
#define RAWRECORD_H_

#include "Block.h"

class RawRecord
{
private:
	char* _content;
	T_BLOCKSIZE _size;
public:
	RawRecord(char* content, T_BLOCKSIZE size);
	T_BLOCKSIZE getSize();
	char* getContent();
	
	virtual ~RawRecord();
};

#endif /*RAWRECORD_H_*/
