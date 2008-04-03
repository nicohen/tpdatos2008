#ifndef STATEMENTPARSEREXCEPTION_H_
#define STATEMENTPARSEREXCEPTION_H_

class StatementParserException
{
private:
	char* _msg;
public:
	StatementParserException(char* msg);
	virtual ~StatementParserException();
};

#endif /*STATEMENTPARSEREXCEPTION_H_*/
