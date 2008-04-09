#ifndef ASSERTION_H_
#define ASSERTION_H_


class Assertion{
private:
	bool _passed;
public:
	//Constructores y destructores 	
	Assertion();
	
	virtual ~Assertion();

	bool evaluate();
	virtual void printFailMessage()=0;
	void reportAssertionFailed();
};

#endif /*ASSERTION_H_*/
