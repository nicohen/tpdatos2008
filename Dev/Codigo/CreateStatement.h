#ifndef CREATESTATEMENT_H_
#define CREATESTATEMENT_H_
#include "SecondaryIndex.h"
#include "Statement.h"
#include "Field.h"
#include <vector>
class CreateStatement: public Statement
{
private:
	std::vector<Field*>* _secondaryFields;
	SecondaryIndex* _secondaryIndex;
	int _dataBlockSize;
	int _indexSize;
public:
	//Constructores y destructores 
	CreateStatement(char* fileName);
	virtual ~CreateStatement();
		
	//Getters
	std::vector<Field*>* getSecondaryFields();
	int getDataBlockSize();
	int getIndexSize();
	SecondaryIndex* getSecondaryIndex();
	
	//Setters
	void setSecondaryIndex(SecondaryIndex* aSecondaryIndex);
	void setDataBlockSize(int size);
	void setIndexSize(int size);
	
	//Otros metodos
	void addSecondaryField(Field* aField);
	virtual void execute(void* anIDataManager, OutPutter* anOutputter);
	
};




#endif /*CREATESTATEMENT_H_*/
