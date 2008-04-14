#ifndef METADATABLOCK_H_
#define METADATABLOCK_H_

#include "../Field.h"
#include "BlockStructuredFileHeader.h"
#include <vector>

using namespace std;

class MetadataBlock {
	
private:
	int _indexSize;
	// {"secuencial","hash","secIndexado","indexado"}
	int _fileType;
	int _qtyFields;
	vector<Field*>* _fields;
	
public:
	MetadataBlock();
	virtual ~MetadataBlock(void);
	char* serialize();

	int getIndexSize();
	void setIndexSize(int indexSize);
	int getFileType();
	void setFileType(int fileType);
	int getQtyFields();
	void setQtyFields(int qtyFields);
	void setSecondaryField(Field* field);
	void setSecondaryFields(vector<Field*>* _fields);
	Field* getNextSecondaryField();
};

#endif /*METADATABLOCK_H_*/
