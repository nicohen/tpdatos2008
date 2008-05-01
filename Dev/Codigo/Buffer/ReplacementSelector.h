#ifndef REPLACEMENTSELECTOR_H_
#define REPLACEMENTSELECTOR_H_
#include <iostream>
#include <map>
#include "IComparable.h"

using namespace std;

struct Comparator {
	bool operator() (IComparable* i1, IComparable* i2) const {
		return i1->isLowerThan(i2);
	}
};

class ReplacementSelector {

private:
	map<IComparable*, int, Comparator>* _itemsMap;
	
public:
	ReplacementSelector();
	virtual ~ReplacementSelector();
	void setItem(IComparable* key);
	void notifyHit(IComparable* key);
	void notifyDelete(IComparable* key);
	IComparable* getUnusedItem();	
};

#endif /*REPLACEMENTSELECTOR_H_*/
