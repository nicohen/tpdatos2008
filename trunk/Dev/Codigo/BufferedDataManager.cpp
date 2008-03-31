#include "BufferedDataManager.h"

BufferedDataManager::BufferedDataManager(DataManager* dataManager)
{
}

BufferedDataManager::~BufferedDataManager()
{
}

/*
 * Devuelve true si encuentra el statement en el caché, en caso contraro false.
 * Si encuentra el statemente en el chaché lo asigna al parametro result*/

bool BufferedDataManager::tryGetResultFromCache(Statement* aStatement,StatementResult** result){
	//No implementado
	return false;
}

void BufferedDataManager::saveToCache(StatementResult* result){
	//No implementado
	return;
}

StatementResult* BufferedDataManager::executeStatement(Statement* aStatement, OutPutter* outPutter){
	StatementResult* result=NULL;
	if(!tryGetResultFromCache(aStatement,&result)){
		result=aStatement->execute(this->_dataManager);
		saveToCache(result);
	}
	return result;
}


