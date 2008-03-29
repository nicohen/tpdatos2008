#ifndef CREATESTATEMENT_H_
#define CREATESTATEMENT_H_
#include "SecondaryIndex.h"
#include "Field.h"
#include <vector>
class CreateStatement
{
private:
	char* _name;
	std::vector<Field*>* _secondaryFields;
	SecondaryIndex* _secondaryIndex;
	int _dataBlockSize;
	int _indexSize;
public:
	CreateStatement();
	char* getFileName();
	std::vector<Field*>* getSecondaryFields();
	int getDataBlockSize();
	int getIndexSize();
	SecondaryIndex* getSecondaryIndex();
	
	void addSecondaryField(Field* aField);
	void setSecondaryIndex(SecondaryIndex* aSecondaryIndex);
	void setDataBlockSize(int size);
	void setIndexSize(int size);
	void setFileName(char* aName);
	virtual ~CreateStatement();
};




#endif /*CREATESTATEMENT_H_*/
