#ifndef STATEMENTPARSEREXCEPTION_H_
#define STATEMENTPARSEREXCEPTION_H_

class StatementParserException
{
private:
	const char* _msg;
public:
	StatementParserException(const char* msg);
	const char* getMessage(){return _msg;};
	virtual ~StatementParserException();
};

#endif /*STATEMENTPARSEREXCEPTION_H_*/
