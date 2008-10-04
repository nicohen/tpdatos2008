#include "SecondaryIndex.h"

SecondaryIndex::SecondaryIndex(int type, int fieldNumber){
	_indexType= type;
	_fieldNumber= fieldNumber;
}
int SecondaryIndex::getType(){
	return _indexType;
}

int SecondaryIndex::getNumberOfFieldToIndexBy(){
	return _fieldNumber;
}
	
SecondaryIndex::~SecondaryIndex(){
}


