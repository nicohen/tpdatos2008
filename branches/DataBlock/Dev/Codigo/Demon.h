#ifndef DEMON_H_
#define DEMON_H_
#include "BufferedDataManager.h"
#include "OutPutter.h"
#include "Utils.h"

class Demon {
	
	private:
	int _sleepTime;
	int _bufferSize;
	bool _finishDaemon;
	
	public:
	Demon(int st, int bs);
	void run(void);
	void processInputStatements(BufferedDataManager* bufferedDataManager, OutPutter* outPutter, FileManager::FileInfo* inputFile);
	virtual ~Demon();
	
};

#endif /*DEMON_H_*/
