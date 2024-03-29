#ifndef RecordsBlock_H_
#define RecordsBlock_H_

#include "Block.h"
#include "RawRecord.h"
#include <vector>


//Forma de serializarse: Cantidad de registros| {Tamaño registro siguiente| Datos Registro} 
using namespace std;
class RecordsBlock: public Block
{
private:
	vector<RawRecord*>* _records;
	//void writeRecord(char* content, T_BLOCKSIZE recordSize,T_BLOCKSIZE offset);
	void writeAllRecords();
	void writeOnBlock(RawRecord* record,Block* block,T_BLOCKSIZE offset);
	static T_BLOCKSIZE getSerializationSize(RawRecord* record);
	void deserializeRecords();
	RawRecord* deserializeRecord(char* data, T_BLOCKSIZE offset);

public:
//	static Block* createRecordsBlock(char* content, T_BLOCKSIZE size);
	RecordsBlock(T_BLOCKSIZE size);
	RecordsBlock(char* content,T_BLOCKSIZE size);
	virtual ~RecordsBlock(void);

	vector<RawRecord*>* getRecords();

	virtual void appendRecord(RawRecord* record);
	virtual T_BLOCKSIZE getUsedSpace();
	virtual char* getContent();
	virtual void push_back(RawRecord* rawrecord);
	
	virtual vector<RawRecord*>::iterator begin();
	virtual vector<RawRecord*>::iterator end();
	virtual void erase(vector<RawRecord*>::iterator it);
	virtual T_BLOCKSIZE RecordCount();
	virtual RawRecord* at(T_BLOCKSIZE i);
	virtual void clear();
	virtual bool canUpdate(RawRecord* current, RawRecord* newOne);
	static bool canInsert(int size, RawRecord* record);
	virtual int getAvaliableSpace();
	virtual void toString(string* buffer);
};

#endif /*RecordsBlock_H_*/
