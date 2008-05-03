#ifndef ICOMPARABLE_H_
#define ICOMPARABLE_H_

class IComparable
{
public:
	IComparable();
	virtual ~IComparable();
	virtual char* toString()=0;
	virtual bool isLowerThan(IComparable* other)=0;
};

#endif /*ICOMPARABLE_H_*/
