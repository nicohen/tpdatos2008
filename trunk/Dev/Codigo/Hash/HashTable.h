#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#import "stdio.h"

class HashTable{
	private:
		int _size;
		FILE* _hashFile;
		char* _fileName;
		
		static const int INT_SIZE= sizeof(int);
	public:
		HashTable();
		virtual ~HashTable();
		void create(char* filePath, int size);
		void load(char* filePath);
		void deleTe();
		int getSize();
		int getAt(int i);
		void update(int index, int value);
		void grow();
		void simplify();
};

#endif /*HASHTABLE_H_*/
