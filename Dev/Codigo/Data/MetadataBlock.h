#ifndef METADATABLOCK_H_
#define METADATABLOCK_H_

#include "../Field.h"
#include "BlockStructuredFileHeader.h"
#include <vector>

using namespace std;

class MetadataBlock: public Block{
	
private:
	unsigned short int _fileType;
	vector<Field*>* _fields;
	
	Field* parseField(char* content, int* offset);
	void writeFieldOnBlock(Field* field,Block* block,int* offset);	
public:
	static Block* createMetadataBlock(char* content, T_BLOCKSIZE size);
	
	MetadataBlock(T_BLOCKSIZE size);
	MetadataBlock(char* content,T_BLOCKSIZE size);
	virtual ~MetadataBlock(void);
	//char* serialize();

	//int getIndexSize();
	//void setIndexSize(int indexSize);
	int getFileType();
	void setFileType(int fileType);
	int getQtyFields();
	void setSecondaryField(Field* field);
	void setSecondaryFields(vector<Field*>* _fields);
	vector<Field*>* GetSecondaryFields();
	Field* getNextSecondaryField();
	
	//METODOS HEREDADOS
	virtual void setContent(char* content);
	void deserialize(char* content);
	virtual void setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size);
	virtual char* getContent();
	
	virtual T_BLOCKSIZE getUsedSpace();
};

#endif /*METADATABLOCK_H_*/
