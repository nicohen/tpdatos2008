#ifndef REPLACEMENTSELECTOR_H_
#define REPLACEMENTSELECTOR_H_
#include <iostream.h>
#include <map>
#include "IComparable.h"

using namespace std;

struct strCmp {
	bool operator() (IComparable* i1, IComparable* i2) const {
		return i1->isLowerThan(i2);
	}
};

class ReplacementSelector {

private:
	map<IComparable*, int, strCmp>* _itemsMap;
	
public:
	ReplacementSelector();
	virtual ~ReplacementSelector();
	void setItem(IComparable* key);
	void notifyHit(IComparable* key);
	void notifyDelete(IComparable* key);
	IComparable* getUnusedItem();	
};

#endif /*REPLACEMENTSELECTOR_H_*/
