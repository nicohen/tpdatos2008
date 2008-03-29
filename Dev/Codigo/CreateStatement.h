#ifndef CREATESTATEMENT_H_
#define CREATESTATEMENT_H_
#include "SecondaryIndex.h"
#include "Field.h"
#include <vector>
class CreateStatement
{
private:
	char* _name;
public:
	CreateStatement();
	char* getFileName();
	std::vector<Field*>* getSecondaryFields();
	int getDataBlockSize();
	int getIndexSize();
	SecondaryIndex* getSecondaryIndex();
	
	void setFileName(char* aName);
	virtual ~CreateStatement();
};




#endif /*CREATESTATEMENT_H_*/
