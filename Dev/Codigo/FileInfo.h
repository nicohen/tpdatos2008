#ifndef FILEINFO_H_
#define FILEINFO_H_

#include "stdio.h"
#include "Utils.h"

class FileInfo{

	private:
	char* _name;
	FILE* _file;
	
	public:
	FileInfo(char* fileName);
	virtual ~FileInfo();
	
	// GETERS y SETERS NECESARIOS
	char* getFileName(void){return _name;};
	void setFile(FILE* file){_file = file;};
	FILE* getFile(void){return _file;};
	
	void open(char* mode);
	void close(void);
	int read(void* place,int size);
	void write(void* source, int size);
	void create(char* mode);
	void delet(void);
	void flush();
};

#endif /*FILEINFO_H_*/
