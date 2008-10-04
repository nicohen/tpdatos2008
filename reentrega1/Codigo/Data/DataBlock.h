/*
 #ifndef DataBlock_H_
#define DataBlock_H_


class DataBlock{
private:
	char* _filename;
	int _size;
	char* _buffer;
public:
	//Constructores y destructores 	
	DataBlock(char* filename,int size);	
	virtual ~DataBlock();


	void clear();
	void writeRecord(char* recordContent);
	void update();
	void flush();
};
#endif /*DataBlock*/
*/