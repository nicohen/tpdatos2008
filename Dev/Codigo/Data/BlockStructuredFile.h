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

typedef unsigned int T_FILESIZE;//sizeof(T_BLOCKCOUNT) * sizeof(T_BLOCKSIZE)
class BlockStructuredFile
{

private: 
	fstream* _file;
	char* _filename;
	BlockStructuredFileHeader* _header;

	BlockStructuredFile(char* filename);
	void load(T_BLOCKSIZE blockSize);
	void saveHeader();
	
	void setBlockSize(T_BLOCKSIZE size);
	void setBlockCount(T_BLOCKCOUNT count);
	T_BLOCKCOUNT getAbsoluteBlockNumberFromContentBlockNumber(T_BLOCKCOUNT contentBlockNumber);
	T_BLOCKCOUNT getHeaderBlockCount();
	T_FILESIZE  getBlockFilePositionFromAbsoluteBlockCount(T_BLOCKCOUNT contentBlockNumber);
	void updateBlock(T_BLOCKCOUNT blockNumber,char* content);
	void notifyBlockUpdated(T_BLOCKCOUNT blockNumber);
public:
	
	char* getBlock(T_BLOCKCOUNT blockNumber);//ESTO ES PRIVADO

	static BlockStructuredFile* Load(char* filename);
	static BlockStructuredFile* Create(char* filename,T_BLOCKSIZE blockSize);
	
	char* getContentBlock(T_BLOCKCOUNT contentBlockNumber);	//El resultado es un puntero alocado en memoria dinamica, por lo tanto hay que eliminarlo
	
	
	void updateContentBlock(T_BLOCKCOUNT contentBlockNumber,char* content);
	void appendBlock(char* content);
	void removeBlock(T_BLOCKCOUNT contentBlockNumber);	
	void moveBlock(T_BLOCKCOUNT currentContentBlockNumber,T_BLOCKCOUNT destContentBlockNumber);	
	T_BLOCKSIZE getBlockSize();
	T_BLOCKCOUNT getBlockCount();
	T_BLOCKCOUNT getFirstFreeBlockNumber();
	T_BLOCKCOUNT getContentBlockCount();
	
	virtual ~BlockStructuredFile(void);
};

#endif /*BlockStructuredFile_H_*/


