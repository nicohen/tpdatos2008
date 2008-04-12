#ifndef RecordsBlock_H_
#define RecordsBlock_H_

class RecordsBlock
{
	char* _content;
public:
	
	RecordsBlock(char* content);
	RecordsBlock();
	virtual ~RecordsBlock(void);

	void appendRecord(char* content);
	
	char* moveFirst();
	char* moveNext();
	char* getCurrent();
	bool hasNext();
	void deleteCurrent();
	int getFreeSpace();

};

#endif /*RecordsBlock_H_*/
