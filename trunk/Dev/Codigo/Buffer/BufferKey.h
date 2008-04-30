#ifndef BUFFERKEY_H_
#define BUFFERKEY_H_

class BufferKey{
	private:
		char* _fileName;
		int _blockNumber;
public:
	BufferKey(char* fileName, int block);
	char* getFileName(void);
	int getBlockNumber(void);
	virtual ~BufferKey();
};

#endif /*BUFFERKEY_H_*/
