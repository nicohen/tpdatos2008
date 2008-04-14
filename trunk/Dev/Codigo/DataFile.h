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
#include <vector>

class DataFile {

private:
	DataType* _keyField;
	vector<DataType*>* _secondaryFields;
	int _blockSize;
	char* _fileName;
	MetadataBlock* _metadataBlock;
	BlockStructuredFile* _blockStructuredFile;
	
public:
	//Constructores y destructores 
	DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex);
	virtual ~DataFile();
	
	void create();
	char* getFileName();
	int getBlockSize();
	
	
	void setBlockStructuredFile(BlockStructuredFile* blockStructuredFile);
	BlockStructuredFile* getBlockStructuredFile();
	void setMetadataBlock(MetadataBlock* metadataBlock);
	MetadataBlock* getMetadataBlock();

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
