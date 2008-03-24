#ifndef DEMON_H_
#define DEMON_H_

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
#include "FileInfo.h"

class Demon{
	
	private:
	int _sleepTime;
	int _bufferSize;
	bool _vervose;
	
	public:
	Demon(int st, int bs, bool v);
	void run(void);
	virtual ~Demon();
	
};

#endif /*DEMON_H_*/
