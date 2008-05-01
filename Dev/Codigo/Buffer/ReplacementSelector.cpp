#include "ReplacementSelector.h"

ReplacementSelector::ReplacementSelector() {
	this->_itemsMap = new map<IComparable*, int, strCmp>();
}

ReplacementSelector::~ReplacementSelector() {
	this->_itemsMap->clear();
	delete this->_itemsMap;
}

void ReplacementSelector::setItem(IComparable* key) {
	this->_itemsMap->insert(make_pair(key,1));
}

void ReplacementSelector::notifyHit(IComparable* key) {
	(*this->_itemsMap)[key]++;
}

IComparable* ReplacementSelector::getUnusedItem() {
	IComparable* unusedItem = NULL;
	int minValue = 0;
	bool firstElement = true;
	
	for (map<IComparable*, int, strCmp>::iterator iter = this->_itemsMap->begin(); iter!=this->_itemsMap->end(); iter++) {
		if (firstElement) {
			unusedItem = ((*iter).first);
			minValue = ((*iter).second);
			firstElement = false;
		} else {
			if (((*iter).second)<minValue) {
				unusedItem = ((*iter).first);
				minValue = ((*iter).second);
			}
		}
	}
	
	return unusedItem;
}
