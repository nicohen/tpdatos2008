#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#import "stdio.h"
#import <string>

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
		int getPhysicalSize();
		int getAt(int i);
		void update(int index, int value);
		void grow();
		void simplify();
		void toString(std::string* buffer);
		void append(int value);
		bool removeLast();
};

#endif /*HASHTABLE_H_*/
