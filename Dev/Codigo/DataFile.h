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

class DataFile {

private:
	int _blockSize;
	char* _fileName;
	MetadataBlock* _metadataBlock;
	BlockStructuredFile* _blockStructuredFile;
	char* _fullPath;
	
	bool isArrayOf(vector<Field*>* fields, vector<DataValue*>* values);
public:
	static const int FIRST_BLOCK = 0;
	//static DataFile* Load(char* filename);
	//void create();
	
	//Constructores y destructores 
	DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex);
	DataFile(char* fileName);
	virtual ~DataFile();
	
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
	
	//vector<Field*>* getDataStructure();
	Field* getPrimaryField();
	vector<Field*>* getFields();

	void insertRecord(Record* record);
	vector<Record*>* findRecords(int fNumber,DataValue* fValue);
	vector<Record*>* removeRecord(int fNumber,DataValue* fValue);
	bool updateRecord(Record* record);
	/*
	void open();
	void close();
	void insert(Record* record);
	void remove();
	Record* find(int fieldNumber, DataValue* expectedData);
	Record* createRecord();
	int delet(int fieldNumber, DataValue* expectedData);
	Record* readRecord();
	*/
};

#endif /*DATAFILE_H_*/
