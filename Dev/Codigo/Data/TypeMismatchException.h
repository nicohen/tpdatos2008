#ifndef TYPEMISMATCHEXCEPTION_H_
#define TYPEMISMATCHEXCEPTION_H_

class TypeMismatchException
{
	char* _msg;
public:
	TypeMismatchException(char* msg);
	virtual ~TypeMismatchException();
	char* toString();
};

#endif /*TYPEMISMATCHEXCEPTION_H_*/
