#include "ReplacementSelector.h"
//#include "BufferKey.h"

ReplacementSelector::ReplacementSelector() {
	this->_itemsMap = new map<IComparable*, int, Comparator>();
}

ReplacementSelector::~ReplacementSelector() {
	this->_itemsMap->clear();
	delete this->_itemsMap;
}

void ReplacementSelector::setItem(IComparable* key) {
	this->_itemsMap->insert(make_pair(key,0));
}

void ReplacementSelector::notifyHit(IComparable* key) {
	(*this->_itemsMap)[key]++;
}

void ReplacementSelector::notifyDelete(IComparable* key) {
	this->_itemsMap->erase(key);
}

IComparable* ReplacementSelector::getUnusedItem() {
	IComparable* unusedItem = NULL;
	int minValue = 0;
	bool firstElement = true;
	
	for (map<IComparable*, int, Comparator>::iterator iter = this->_itemsMap->begin(); iter!=this->_itemsMap->end(); iter++) {
//		printf("\nAnalizando [key:%i] [value:%i]\n",((BufferKey*)((*iter).first))->getBlockNumber(),(*iter).second);
		if (firstElement) {
			unusedItem = ((*iter).first);
			minValue = ((*iter).second);
			firstElement = false;
		} else {
			if (((*iter).second)<minValue) {
//				printf("\n[key:%i][value:%i] es menor que la [minValue:%i]\n",((BufferKey*)((*iter).first))->getBlockNumber(),(*iter).second,minValue);
				unusedItem = ((*iter).first);
				minValue = ((*iter).second);
			}
		}
	}
	
	return unusedItem;
}
