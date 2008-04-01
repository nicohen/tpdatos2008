#ifndef DATATYPE_H_
#define DATATYPE_H_


class DataType
{
private:
public:
	DataType();
	virtual bool isInstanceOf(void* anObject)=0;
	virtual bool equals(DataType* other)=0;
	virtual int getUniqueIdentifier()=0;
	virtual ~DataType();
};

#endif /*DATATYPE_H_*/
