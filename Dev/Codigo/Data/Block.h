#ifndef Block_H_
#define Block_H_

typedef unsigned short T_BLOCKSIZE;
typedef unsigned short T_BLOCKCOUNT;
//No funciona bien, solo usar la interfaz

class Block
{
private:
	char* _content;
	T_BLOCKSIZE _size;
public:
	Block(T_BLOCKSIZE size);
	Block(char* content,T_BLOCKSIZE size);
	~Block(void);

	void set(T_BLOCKSIZE startPos,char* content,int size);
	char* getContent();
	int getSize();
	
};

#endif /*Block_H_*/



