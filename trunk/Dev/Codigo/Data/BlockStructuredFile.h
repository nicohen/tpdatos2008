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
	//typedef Block* (*BlockCreatorFunction)(char* content,T_BLOCKSIZE size);
private: 
	fstream* _file;
	char* _filename;
	BlockStructuredFileHeader* _header;

	void load(T_BLOCKSIZE blockSize);
	void saveHeader();
	
	void setBlockSize(T_BLOCKSIZE size);
	void setBlockCount(T_BLOCKCOUNT count);
	T_BLOCKCOUNT getAbsoluteBlockNumberFromContentBlockNumber(T_BLOCKCOUNT contentBlockNumber);
	T_BLOCKCOUNT getHeaderBlockCount();
	T_FILESIZE  getBlockFilePositionFromAbsoluteBlockCount(T_BLOCKCOUNT contentBlockNumber);
	void updateBlock(T_BLOCKCOUNT blockNumber,char* content);
	void notifyBlockUpdated(T_BLOCKCOUNT blockNumber);
	T_BLOCKCOUNT getLastBlockIndex();
	
	char* getContentBlock(T_BLOCKCOUNT contentBlockNumber);	//El resultado es un puntero alocado en memoria dinamica, por lo tanto hay que eliminarlo
	void updateContentBlock(T_BLOCKCOUNT contentBlockNumber,char* content);
	void appendBlock(char* content);
public:
	
	BlockStructuredFile(char* filename);
	
	static BlockStructuredFile* Load(char* filename);
	static BlockStructuredFile* Create(char* filename,T_BLOCKSIZE blockSize);

	char* getBlock(T_BLOCKCOUNT blockNumber);//ESTO ES PRIVADO
	
	T_BLOCKSIZE getBlockSize();
	T_BLOCKCOUNT getBlockCount();
	T_BLOCKCOUNT getContentBlockCount();
	
	//No implementados
	void removeBlock(T_BLOCKCOUNT contentBlockNumber);	
	void moveBlock(T_BLOCKCOUNT currentContentBlockNumber,T_BLOCKCOUNT destContentBlockNumber);
	T_BLOCKCOUNT getFirstFreeBlockNumber();
	
	//Nuevos metodos que usan Block	
	void bUpdateContentBlock(T_BLOCKCOUNT contentBlockNumber,Block* block);	
	Block* bGetContentBlock(T_BLOCKCOUNT contentBlockNumber,Block* (*BlockCreatorFunction)(char* content,T_BLOCKSIZE size));
	void bAppendContentBlock(Block* block);
	void removeLastContentBlock();
	
	virtual ~BlockStructuredFile(void);
};

#endif /*BlockStructuredFile_H_*/


