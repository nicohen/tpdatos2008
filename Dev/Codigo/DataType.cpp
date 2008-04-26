#include "DataType.h"

#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"

DataType::DataType()
{
}

DataType::~DataType()
{
}

DataType* DataType::createType(char type){
	if(type==DataType::STRING_TYPE){
		return new StringType();
	}else if(type==DataType::INT_TYPE){
		return new IntType();
	}else if(type==DataType::STRUCTURED_TYPE){
		return new StructureType();
	}else{
		throw "EXCEPTION en createType. type desconocido";
	}
}
