#ifndef Block_H_
#define Block_H_

typedef unsigned short T_BLOCKSIZE;
typedef unsigned short T_BLOCKCOUNT;

class Block
{
private:
	char* _content;
	T_BLOCKSIZE _size;
public:
	Block(T_BLOCKSIZE size);
	Block(char* content,T_BLOCKSIZE size);
	virtual ~Block(void);

	virtual void setContent(char* content);
	virtual void setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size);
	virtual char* getContent();
	virtual T_BLOCKSIZE getSize();	
	virtual T_BLOCKSIZE getFreeSpace();//Esto deberia ser sobreescrito por otros blocks
	
};

#endif /*Block_H_*/



