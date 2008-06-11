#ifndef KEYSBLOCK_H_
#define KEYSBLOCK_H_

#include "RecordsBlock.h"
#include "../IntValue.h"
#include "../Field.h"
#include <vector>

class KeysBlock : public RecordsBlock
{
	
private:
	vector<Field*>* _fieldList;
	
public: 
	virtual ~KeysBlock();
	static Block* createKeysBlock(char* content, T_BLOCKSIZE size);
	KeysBlock(T_BLOCKSIZE size,int dispersion);
	KeysBlock(char* content,T_BLOCKSIZE size);
	
	virtual vector<RawRecord*>::iterator begin();
	virtual vector<RawRecord*>::iterator end();
	virtual void erase(vector<RawRecord*>::iterator it);
	virtual T_BLOCKSIZE RecordCount();
	virtual RawRecord* at(T_BLOCKSIZE i);
	virtual void clear();
	
	void loadDispersionField();
	int getDispersion();
	virtual void toString(string* buffer);

	void setDispersion(int dispersion);
	virtual int getAvaliableSpace();
};

#endif /*KEYSBLOCK_H_*/
