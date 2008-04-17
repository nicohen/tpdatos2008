#ifndef SECONDARYINDEX_H_
#define SECONDARYINDEX_H_

class SecondaryIndex{
private:
	int _indexType;
	int _fieldNumber;
public:
	SecondaryIndex(int type, int fieldNumber);
	int getType();
	int getNumberOfFieldToIndexBy();
	~SecondaryIndex();
};
#endif /*SECONDARYINDEX_H_*/
