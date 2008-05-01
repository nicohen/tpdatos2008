#ifndef IBUFFEREABLE_H_
#define IBUFFEREABLE_H_

typedef unsigned short T_BLOCKSIZE;

class IBuffereable
{
public:
	IBuffereable();
	virtual T_BLOCKSIZE getSize()=0;
	virtual ~IBuffereable();
};

#endif /*IBUFFEREABLE_H_*/
