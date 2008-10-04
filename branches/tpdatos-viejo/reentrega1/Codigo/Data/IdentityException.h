#ifndef IDENTITYEXCEPTION_H_
#define IDENTITYEXCEPTION_H_

class IdentityException
{
	char* _msg;
public:
	IdentityException(char* msg);
	virtual ~IdentityException();
	char* toString();
};

#endif /*IDENTITYEXCEPTION_H_*/
