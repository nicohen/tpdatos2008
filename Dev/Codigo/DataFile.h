#ifndef DATAFILE_H_
#define DATAFILE_H_

#include "DataType.h"
#include "Data/RecordsBlock.h"
#include "DataValue.h"
#include "Data/MetadataBlock.h"
#include "Data/BlockStructuredFile.h"
#include "Utils.h"
#include "Data/Record.h"
#include "SecondaryIndex.h"
#include "Data/Block.h"
#include "Data/RawRecord.h"
#include <vector>
#include "Buffer/BlocksBuffer.h"
#include "Buffer/IBuffereable.h"
#include "Data/BlockFactory.h"
#include "Data/RecordsBlockFactory.h"
#include "Data/MetadataBlockFactory.h"
#include "Indexes/HashIndex.h"
#include "Indexes/IIndex.h"


class HashIndex;
class DataFile:public IBuffereable
{

private:
	static const unsigned short int SECUENTIAL=100;
	static const unsigned short int HASH_INDEX=101;
			
	
	int _blockSize;
	char* _fileName;
	MetadataBlock* _metadataBlock;
	BlockStructuredFile* _blockStructuredFile;
	char* _fullPath;
	BlocksBuffer* _blocksBuffer;
	BlockFactory* _blockFactory;
	MetadataBlockFactory _metadataBlockFactory;
	IIndex* _primaryIndex;
	
	bool isArrayOf(vector<Field*>* fields, vector<DataValue*>* values);
	T_BLOCKCOUNT getFirstFreeContentBlockNumber(T_BLOCKCOUNT initBlockNumber, T_BLOCKSIZE minRequiredSpace) throw (BlockNotFoundException*);
	T_BLOCKCOUNT getFirstRecordsBlockIndex();
	bool canInsert(Record* record);
public:
	T_BLOCKCOUNT getLastRecordsBlockIndex();
	
	
	
	virtual BlockFactory* getBlockFactory();
	virtual void setBlockFactory(BlockFactory* blockFactory);
	
//	Implementacion de IBuffereable
	virtual T_BLOCKSIZE getSize();
	static const int FIRST_BLOCK = 0;
	
	//Constructores y destructores 
	DataFile(char* fileName, int blockSize,Field* keyField, vector<Field*>* secondaryFields,IIndex* index);
	
	DataFile(char* fileName);
	virtual ~DataFile();
	
	void setBlocksBuffer(BlocksBuffer* blocksBuffer);
	void load(char* folderpath);
	void save(char* folderPath);
	void deleTe();
	void setFolder(char* folderPath);
	char* appendFolder(char* fileName, char* folderPath);
	
	char* getFileName();	
	void setBlockStructuredFile(BlockStructuredFile* blockStructuredFile);
	BlockStructuredFile* getBlockStructuredFile();
	void setMetadataBlock(MetadataBlock* metadataBlock);
	RecordsBlock* getRecordBlock(int blockNumber);
	T_FILESIZE getDataUsedSpace();
//	T_FILESIZE getIndexUsedSpace();
	T_FILESIZE getDataFreeSpace();
	T_FILESIZE getFileSize();
	T_BLOCKSIZE getDataRecordsCount();
	T_BLOCKSIZE getRecordsBlockCount();
	
	Field* getPrimaryField();
	vector<Field*>* getFields();

	virtual int insertRecord(Record* record);
	virtual void insertRecordAt(T_BLOCKCOUNT blockNumber, Record* record);
	virtual vector<Record*>* findRecords(int fNumber,DataValue* fValue);
	virtual vector<Record*>* findRecordsAt(T_BLOCKCOUNT blockNumber, int fNumber,DataValue* fValue);
	virtual vector<Record*>* removeRecord(int fNumber,DataValue* fValue);
	vector<Record*>* removeRecordAt(T_BLOCKCOUNT blockNumber, int fNumber,DataValue* fValue) throw (BlockNotFoundException*);
	vector<Record*>* removeRecordsAt(T_BLOCKCOUNT blockNumber);
	virtual bool updateRecord(Record* record);
	bool updateRecordAt(T_BLOCKCOUNT blockNumber,Record* record);
	RecordsBlock* appendEmptyBlock();
	bool existsAnotherWithSameKey(Record* record);
	virtual void toString(string* buffer);
//	virtual void setPrimaryIndex(HashIndex* index);
};

#endif /*DATAFILE_H_*/
