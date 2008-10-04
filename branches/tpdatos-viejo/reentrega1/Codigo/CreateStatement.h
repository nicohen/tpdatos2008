#ifndef CREATESTATEMENT_H_
#define CREATESTATEMENT_H_
#include "SecondaryIndex.h"
#include "Statement.h"
#include "Field.h"
#include <vector>

using namespace std;

class CreateStatement: public Statement
{
private:
	int _fileType;
	std::vector<Field*>* _secondaryFields;
	SecondaryIndex* _secondaryIndex;
	int _dataBlockSize;
	int _indexSize;
public:
	//Constructores y destructores 
	CreateStatement(char* fileName);
	virtual ~CreateStatement();
		
	//Getters
	vector<Field*>* getSecondaryFields();
	int getDataBlockSize();
	int getIndexSize();
	SecondaryIndex* getSecondaryIndex();
	int getFileType();
	int getSecondaryFieldCount();
	
	//Setters
	void setSecondaryIndex(SecondaryIndex* aSecondaryIndex);
	void setDataBlockSize(int size);
	void setIndexSize(int size);
	void setFileType(int fileType);
	//Otros metodos
	void addSecondaryField(Field* aField);
	void addSecondaryFields(vector<Field*>* fieldList);
	virtual void writeStatementQuery(OutPutter* outPutter);
	virtual StatementResult* execute(DataManager* dataManager);
private:
	//Otros metodos
	void clearSecondaryFields(vector<Field*>* secondaryFields);
	
	
};




#endif /*CREATESTATEMENT_H_*/
