#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

class FileNotFoundException
{
	char* _msg;
public:
	FileNotFoundException(char* msg);
	virtual ~FileNotFoundException();
	char* toString();
};

#endif /*FILENOTFOUNDEXCEPTION_H_*/
