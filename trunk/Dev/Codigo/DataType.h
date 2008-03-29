#ifndef DATATYPE_H_
#define DATATYPE_H_

class DataType
{
public:
	DataType();
	virtual bool isInstanceOf(void* anObject)=0;
	virtual ~DataType();
};

#endif /*DATATYPE_H_*/
