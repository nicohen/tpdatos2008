#ifndef DEMON_H_
#define DEMON_H_

class Demon{
	
	private:
	int _sleepTime;
	int _bufferSize;
	bool _verbose;
	
	public:
	Demon(int st, int bs, bool v);
	void run(void);
	virtual ~Demon();
	
};

#endif /*DEMON_H_*/
