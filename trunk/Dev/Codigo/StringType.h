#ifndef STRINGTYPE_H_
#define STRINGTYPE_H_

class StringType
{
public:
	StringType();
	virtual bool isInstanceOf(void* anObject);
	virtual ~StringType();
};

#endif /*STRINGTYPE_H_*/
