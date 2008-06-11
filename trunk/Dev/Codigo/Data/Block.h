#ifndef Block_H_
#define Block_H_

#include "../Buffer/IBuffereable.h"
typedef unsigned short T_BLOCKSIZE;
typedef unsigned short T_BLOCKCOUNT;
typedef unsigned int T_FILESIZE;//sizeof(T_BLOCKCOUNT) * sizeof(T_BLOCKSIZE)

class Block:public IBuffereable
{
private:
	char* _content;
	T_BLOCKSIZE _size;
	T_BLOCKSIZE _freeSpace;
public:
	Block(T_BLOCKSIZE size);
	Block(char* content,T_BLOCKSIZE size);
	virtual ~Block(void);

	virtual void setContent(char* content);
	virtual void setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size);
	virtual char* getContent();
	
	virtual T_BLOCKSIZE getSize();
	virtual int getAvaliableSpace();//Esto deberia ser sobreescrito por otros blocks
};

#endif /*Block_H_*/



