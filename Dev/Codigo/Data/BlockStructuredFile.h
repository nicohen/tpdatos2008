#ifndef BlockStructuredFile_H_
#define BlockStructuredFile_H_

#include "Block.h"
#include <fstream>
#include "BlockStructuredFileHeader.h"
#include "BlockStructuredFileException.h"
#include "BlockNotFoundException.h"
#include "RecordsBlock.h"
#include "BlockFactory.h"

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
	
	BlockStructuredFile(char* filename);
public:
	
	static BlockStructuredFile* Load(char* filename);
	static BlockStructuredFile* Create(char* filename,T_BLOCKSIZE blockSize);

	char* getBlock(T_BLOCKCOUNT blockNumber) throw (BlockStructuredFileException*);//ESTO ES PRIVADO
	
	T_FILESIZE getFileSize();
	T_BLOCKSIZE getBlockSize();
	T_BLOCKCOUNT getBlockCount();
	T_BLOCKCOUNT getContentBlockCount();
	
	//Nuevos metodos que usan Block	
	void bUpdateContentBlock(T_BLOCKCOUNT contentBlockNumber,Block* block);	
	Block* bGetContentBlock(T_BLOCKCOUNT contentBlockNumber,BlockFactory* blockFactory);
	void bAppendContentBlock(Block* block);
	
	void deleTe();
	
	virtual ~BlockStructuredFile(void);
};

#endif /*BlockStructuredFile_H_*/


