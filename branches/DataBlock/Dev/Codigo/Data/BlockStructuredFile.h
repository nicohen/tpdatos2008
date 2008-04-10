#pragma once

class BlockStructuredFile
{
private: 
	char* _filename;
	int _blockSize;	
	BlockStructuredFile(char* filename);
public:

	static BlockStructuredFile* Load(char* filename);
	static BlockStructuredFile* Create(char* filename,int blockSize);
	
	char* getBlock(int blockNumber);
	void updateBlock(int blockNumber,char* content);
	void appendBlock(char* content);
	void removeBlock(int blockNumber);	
	void moveBlock(int currentBlockNumber,int destBlockNumber);	
	int getBlockSize();
	int getBlockCount();
	int getFirstFreeBlockNumber();
	virtual ~BlockStructuredFile(void);
};
