#ifndef RecordsBlock_H_
#define RecordsBlock_H_

#include "Block.h"
#include "RawRecord.h"
#include <vector>

using namespace std;
class RecordsBlock: public Block
{
private:
	vector<RawRecord*>* _records;
	void writeRecord(char* content, T_BLOCKSIZE recordSize,T_BLOCKSIZE offset);
	void writeAllRecords();
public:
	
	RecordsBlock(T_BLOCKSIZE size);
	RecordsBlock(char* content,T_BLOCKSIZE size);
	virtual ~RecordsBlock(void);

	void appendRecord(char* content,T_BLOCKSIZE recordSize);
	
	char* moveFirst();
	char* moveNext();
	char* getCurrent();
	bool hasNext();
	void deleteCurrent();
	virtual T_BLOCKSIZE getFreeSpace();
	virtual char* getContent();

};

#endif /*RecordsBlock_H_*/
