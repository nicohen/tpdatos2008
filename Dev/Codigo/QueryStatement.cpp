#include "QueryStatemet.h"
#include "Utils.h"

QueryStatemet::QueryStatemet(char* filename):Statement(filename){
}


void QueryStatemet::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción ConsultStatemet");
}

QueryStatemet::~QueryStatemet(){
}
