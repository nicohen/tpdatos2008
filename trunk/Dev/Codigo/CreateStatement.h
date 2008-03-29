#ifndef CREATESTATEMENT_H_
#define CREATESTATEMENT_H_

class CreateStatement
{
public:
	CreateStatement();
	char* getFileName();
//	int[] getSecondaryFields();
	int getFileType();
	int getDataBlockSize();
	int getIndexSize();
	
//	SecondaryIndex* getSecondaryIndex();	
	
	virtual ~CreateStatement();
};




#endif /*CREATESTATEMENT_H_*/
