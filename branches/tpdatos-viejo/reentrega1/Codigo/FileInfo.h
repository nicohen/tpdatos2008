#ifndef FILEINFO_H_
#define FILEINFO_H_

#include "stdio.h"
#include "Utils.h"
#include "FileManager.h"
#include "IOException.h"

namespace FileManager{
	class FileManager;
	class FileInfo{
	
		private:
		char* _name;
		FILE* _file;
		FileManager* _fileManager;
		
		public:
		FileInfo(FileManager* fileManager, char* fileName);
		virtual ~FileInfo();
		
		//GETERS y SETERS NECESARIOS
		char* getFileName(void){return _name;};
		void setFile(FILE* file){_file = file;};
		FILE* getFile(void){return _file;};
		
		void open(void) throw (IOException);
		void open(char* openMode) throw (IOException);
		void close(void) throw (IOException);
		void read(void* place, int size) throw (IOException);
		void write(void* source, int size) throw (IOException);
		void create(void) throw (IOException);
		void delet(void) throw (IOException);
		//void flush();
	};
}
#endif /*FILEINFO_H_*/
