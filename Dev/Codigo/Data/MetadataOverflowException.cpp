#include "MetadataOverflowException.h"

MetadataOverflowException::MetadataOverflowException()
{
}

MetadataOverflowException::~MetadataOverflowException()
{
}

char* MetadataOverflowException::toString()
{
	return (char*)"El tamaño del bloque de metadata no es lo suficientemente grande como para que entre la información necesaria";
}
