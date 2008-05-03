#ifndef COMPARABLEEXAMPLE_H_
#define COMPARABLEEXAMPLE_H_

#include "IComparable.h"

class ComparableExample:public IComparable
{
public:
	int _number;
	ComparableExample(int number);
	virtual bool isLowerThan(IComparable* other);
	virtual char* toString();
	virtual ~ComparableExample();
};

#endif /*COMPARABLEEXAMPLE_H_*/
