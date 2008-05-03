#ifndef SYSTEMBUFFER_H_
#define SYSTEMBUFFER_H_

#include "string.h"
#include "BufferKey.h"
#include <map>
#include "ReplacementSelector.h"
#include "IComparable.h"
#include "IBuffereable.h"

struct bufferKeyCmp {
	bool operator()( IComparable* key1, IComparable* key2 ) const {
		return key1->isLowerThan(key2);
	}
};

class SystemBuffer{
	private:
		map<IComparable*, IBuffereable*, bufferKeyCmp> _buffer;
		unsigned int _bufferSize;
		unsigned int _bufferCurrentSize;
		ReplacementSelector replacementCriteria;
		
		void removeElement(IComparable* bk);
		void makeSpace(int elementSize);
		
	public:
		SystemBuffer(int size);
		void addElement(IComparable* key, IBuffereable* value);
		IBuffereable* getElement(IComparable* key);
		bool isInBuffer(IComparable* key);
		virtual ~SystemBuffer();
};

#endif /*SYSTEMBUFFER_H_*/
