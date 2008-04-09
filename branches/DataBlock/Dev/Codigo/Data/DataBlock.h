#ifndef DataBlock_H_
#define DataBlock_H_


class DataBlock{
private:
	char* _filename;
	int _size;
public:
	//Constructores y destructores 	
	DataBlock(char* filename,int size);	
	virtual ~DataBlock();


	void allocateSpace();
};
#endif /*DataBlock*/
