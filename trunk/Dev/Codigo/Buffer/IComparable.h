#ifndef ICOMPARABLE_H_
#define ICOMPARABLE_H_

class IComparable
{
public:
	IComparable();
	
	virtual bool isLowerThan(IComparable* other)=0;
	virtual ~IComparable();
};

#endif /*ICOMPARABLE_H_*/
