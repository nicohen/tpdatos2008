#include "ConsultStatemet.h"
#include "Utils.h"

ConsultStatemet::ConsultStatemet(char* filename):Statement(filename){
}


void ConsultStatemet::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción ConsultStatemet");
}

ConsultStatemet::~ConsultStatemet(){
}
