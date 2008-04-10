#ifndef BlockStructuredFile_H_
#define BlockStructuredFile_H_

typedef unsigned short T_BLOCKSIZE;
typedef unsigned short T_BLOCKCOUNT;

/*
Archivo:
_
|BlockSize
-
|BlockCount
-
*/

class BlockStructuredFile
{

private: 
	char* _filename;
	T_BLOCKSIZE _blockSize;	
	BlockStructuredFile(char* filename);
	void save();
public:

	static BlockStructuredFile* Load(char* filename);
	static BlockStructuredFile* Create(char* filename,T_BLOCKSIZE blockSize);
	
	char* getBlock(T_BLOCKCOUNT blockNumber);
	void updateBlock(T_BLOCKCOUNT blockNumber,char* content);
	void appendBlock(char* content);
	void removeBlock(T_BLOCKCOUNT blockNumber);	
	void moveBlock(T_BLOCKCOUNT currentBlockNumber,T_BLOCKCOUNT destBlockNumber);	
	T_BLOCKSIZE getBlockSize();
	T_BLOCKCOUNT getBlockCount();
	T_BLOCKCOUNT getFirstFreeBlockNumber();
	virtual ~BlockStructuredFile(void);
};

#endif /*BlockStructuredFile_H_*/