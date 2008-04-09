#ifndef DataBlock_H_
#define DataBlock_H_


class DataBlock{
private:
	char* _filename;
public:
	//Constructores y destructores 	
	DataBlock(char* filename);	
	virtual ~DataBlock();

};
#endif /*DataBlock*/
