#include "ComparableExample.h"

ComparableExample::ComparableExample(int number)
{
	this->_number=number;
}

bool ComparableExample::isLowerThan(IComparable* other){
	ComparableExample* otherComparableExample=(ComparableExample*)other;
	return (this->_number<otherComparableExample->_number);
}

char* ComparableExample::toString() {
	return "ComparableExample";
}

ComparableExample::~ComparableExample()
{
}
