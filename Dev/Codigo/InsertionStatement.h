#ifndef INSERTIONSTATEMENT_H_
#define INSERTIONSTATEMENT_H_
#include "SecondaryIndex.h"
#include "Statement.h"
#include "Field.h"
#include <vector>
class InsertionStatement: public Statement
{
private:
	std::vector<Field*>* _secondaryFields;
	SecondaryIndex* _secondaryIndex;
	int _dataBlockSize;
	int _indexSize;
public:
	//Constructores y destructores 
	InsertionStatement(char* fileName);
	virtual ~InsertionStatement();
		
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




#endif /*INSERTIONSTATEMENT_H_*/
