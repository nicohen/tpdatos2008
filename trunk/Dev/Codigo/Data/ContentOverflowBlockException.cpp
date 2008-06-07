#include "ContentOverflowBlockException.h"

ContentOverflowBlockException::ContentOverflowBlockException()
{
}

ContentOverflowBlockException::~ContentOverflowBlockException()
{
}

char* ContentOverflowBlockException::toString(){
	return (char*)"El tamaño del contenido del bloque es superior al tamaño maximo";
}

