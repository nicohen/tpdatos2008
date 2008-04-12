#ifndef BlockStructuredFile_H_
#define BlockStructuredFile_H_

#include "Block.h"
#include <fstream>
#include "BlockStructuredFileHeader.h"
using namespace std;
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
	fstream* _file;
	char* _filename;
	BlockStructuredFileHeader* _header;
	
	BlockStructuredFile(char* filename);
	void load(T_BLOCKSIZE blockSize);
	void save();
	
	void setBlockSize(T_BLOCKSIZE size);
	void setBlockCount(T_BLOCKCOUNT count);
	
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


