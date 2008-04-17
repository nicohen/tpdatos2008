#ifndef FILEDOESALREADYEXISTSEXCEPTION_H_
#define FILEDOESALREADYEXISTSEXCEPTION_H_

class FileDoesAlreadyExistsException
{
	char* _msg;
public:
	FileDoesAlreadyExistsException(char* msg);
	virtual ~FileDoesAlreadyExistsException();
	char* toString();
};

#endif /*FILEDOESALREADYEXISTSEXCEPTION_H_*/
