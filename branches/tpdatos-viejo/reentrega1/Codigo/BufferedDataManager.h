
#ifndef BUFFEREDDATAMANAGER_H_
#define BUFFEREDDATAMANAGER_H_

//#include "IDataManager.h"
#include "DataManager.h"
#include "Statement.h"
#include "StatementResult.h"
#include "OutPutter.h"

class BufferedDataManager{
private:
	DataManager* _dataManager;
public:
	
	BufferedDataManager(DataManager* dataManager);
	virtual ~BufferedDataManager();
	
	/*
	 * Devuelve true si encuentra el statement en el caché, en caso contraro false.
	 * Si encuentra el statemente en el chaché lo asigna al parametro result*/

	bool tryGetResultFromCache(Statement* aStatement,StatementResult** result);

	void saveToCache(StatementResult* result);

	virtual StatementResult* executeStatement(Statement* aStatement, OutPutter* outPutter);
};

#endif /*BUFFEREDDATAMANAGER_H_*/

