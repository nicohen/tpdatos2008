#ifndef DATAFILESBUFFERKEY_H_
#define DATAFILESBUFFERKEY_H_

#include "IComparable.h"

class DataFilesBufferKey:public IComparable{
	private:
		char* _filename;
public:
	DataFilesBufferKey(char* filename);
	virtual ~DataFilesBufferKey();
	virtual bool isLowerThan(IComparable* other);
	virtual char* toString();
};

#endif /*DATAFILESBUFFERKEY_H_*/
