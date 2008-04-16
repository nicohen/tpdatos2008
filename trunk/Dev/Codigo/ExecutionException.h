#ifndef EXECUTIONEXCEPTION_H_
#define EXECUTIONEXCEPTION_H_

class ExecutionException{
private:
	char* _text;
public:
	ExecutionException(char* cause);
	char* toString(){return _text;};
	virtual ~ExecutionException();
};

#endif /*EXECUTIONEXCEPTION_H_*/
