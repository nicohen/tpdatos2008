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



class DataFile:public IBuffereable
{

private:
	int _blockSize;
	char* _fileName;
	MetadataBlock* _metadataBlock;
	BlockStructuredFile* _blockStructuredFile;
	char* _fullPath;
	BlocksBuffer* _blocksBuffer;
	RecordsBlockFactory _blockFactory;
	
	bool isArrayOf(vector<Field*>* fields, vector<DataValue*>* values);
	T_BLOCKCOUNT getFirstFreeContentBlockNumber(T_BLOCKCOUNT initBlockNumber, T_BLOCKSIZE minRequiredSpace) throw (BlockNotFoundException*);
	T_BLOCKCOUNT getFirstRecordsBlockIndex();
	T_BLOCKCOUNT getLastRecordsBlockIndex();
public:
	
	virtual BlockFactory* getBlockFactory();
	
//	Implementacion de IBuffereable
	virtual T_BLOCKSIZE getSize();
	static const int FIRST_BLOCK = 0;
	
	//Constructores y destructores 
	DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex);
	DataFile(char* fileName);
	virtual ~DataFile();
	
	void setBlocksBuffer(BlocksBuffer* blocksBuffer);
	void load(char* folderpath);
	void save(char* folderPath);
	void setFolder(char* folderPath);
	char* appendFolder(char* fileName, char* folderPath);
	
	char* getFileName();	
	void setBlockStructuredFile(BlockStructuredFile* blockStructuredFile);
	BlockStructuredFile* getBlockStructuredFile();
	void setMetadataBlock(MetadataBlock* metadataBlock);
	RecordsBlock* getRecordBlock(int blockNumber);
	T_FILESIZE getDataUsedSpace();
	T_FILESIZE getDataFreeSpace();
	T_FILESIZE getFileSize();
	T_BLOCKSIZE getDataRecordsCount();
	T_BLOCKSIZE getRecordsBlockCount();
	
	Field* getPrimaryField();
	vector<Field*>* getFields();

	virtual void insertRecord(Record* record);
	void insertRecordAt(T_BLOCKCOUNT blockNumber,Record* record);
	virtual vector<Record*>* findRecords(int fNumber,DataValue* fValue);
	virtual vector<Record*>* removeRecord(int fNumber,DataValue* fValue) throw (BlockNotFoundException*);
	vector<Record*>* removeRecordAt(T_BLOCKCOUNT blockNumber, int fNumber,DataValue* fValue) throw (BlockNotFoundException*);
	virtual bool updateRecord(Record* record);
	void insertRecordAt(T_BLOCKCOUNT blockNumber,Record* record);
	bool updateRecordAt(T_BLOCKCOUNT blockNumber,Record* record);
	void appendEmptyBlock();
	bool existsAnotherWithSameKey(Record* record);
};

#endif /*DATAFILE_H_*/
