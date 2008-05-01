#ifndef COMPARABLEEXAMPLE_H_
#define COMPARABLEEXAMPLE_H_

#include "IComparable.h";

class ComparableExample:public IComparable
{
private:
	int _number;
public:
	ComparableExample(int number);
	virtual bool isLowerThan(IComparable* other);
	virtual ~ComparableExample();
};

#endif /*COMPARABLEEXAMPLE_H_*/
