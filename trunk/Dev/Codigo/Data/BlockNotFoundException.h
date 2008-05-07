#ifndef BLOCKNOTFOUNDEXCEPTION_H_
#define BLOCKNOTFOUNDEXCEPTION_H_

class BlockNotFoundException
{
	
private:
	char* _message;
public:
	BlockNotFoundException(char* message);
	virtual ~BlockNotFoundException();
	char* toString();
};

#endif /*BLOCKNOTFOUNDEXCEPTION_H_*/
