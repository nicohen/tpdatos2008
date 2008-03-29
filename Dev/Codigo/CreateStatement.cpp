#include "CreateStatement.h"

using namespace std;

CreateStatement::CreateStatement()
{
}

char* CreateStatement::getFileName(){
	return NULL;	
}

int CreateStatement::getDataBlockSize(){
	return 0;
}

int CreateStatement::getIndexSize(){
	return 0;	
}

SecondaryIndex* CreateStatement::getSecondaryIndex(){
	return NULL;	
}

vector<Field*>* CreateStatement::getSecondaryFields(){
	vector<Field*>* myVec=NULL;
	myVec=new vector<Field*>();
	//Usa el constructor de copia de la clase vector
	return new vector<Field*>(*myVec);
}

CreateStatement::~CreateStatement()
{
	//ToDo: RECORRER Y MATAR CADA UNO DE LOS ELEMENTOS DEL ARRAY
}
