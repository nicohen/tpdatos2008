#ifndef BLOCKSTRUCTUREDFILEEXCEPTION_H_
#define BLOCKSTRUCTUREDFILEEXCEPTION_H_

class BlockStructuredFileException
{
private:
	char* _message;
public:
	BlockStructuredFileException(char* message);
	virtual ~BlockStructuredFileException();
};

#endif /*BLOCKSTRUCTUREDFILEEXCEPTION_H_*/
