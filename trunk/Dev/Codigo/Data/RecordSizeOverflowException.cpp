#include "RecordSizeOverflowException.h"

RecordSizeOverflowException::RecordSizeOverflowException()
{
}

RecordSizeOverflowException::~RecordSizeOverflowException()
{
}

char* RecordSizeOverflowException::toString(){
	return (char*)"El tamaño del registro es superior al tamaño del bloque";
}
