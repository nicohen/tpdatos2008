#ifndef DATAFILESBUFFER_H_
#define DATAFILESBUFFER_H_

#include "string.h"
#include "DataFilesBufferKey.h"
#include <map>
#include "ReplacementSelector.h"
#include "../DataFile.h"
#include "SystemBuffer.h"

class  DataFilesBuffer{
	private:
		SystemBuffer _systemBuffer;		

	public:
		DataFilesBuffer(int size);
		void addFile(char* filename,DataFile* aDataFile);
		DataFile* getFile(char* fileName);
		void removeFile(char* filename);
		unsigned int getHits();
		unsigned int getMiss();
		unsigned int getTotalSize();
		unsigned int getCurrentSize();
		unsigned int getBlocksCount();
		virtual ~DataFilesBuffer();
};


#endif /*DataFilesBuffer_H_*/
