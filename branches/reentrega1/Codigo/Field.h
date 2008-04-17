#ifndef FIELD_H_
#define FIELD_H_

#include "DataType.h"
#include <stdio.h>
class Field
{
private:
	bool _isMandatory;
	bool _isPolyvalent;
	DataType* _dataType;
	
	void decode(char* byteCode);
public:
	Field();
	Field(char* byteCode);

	virtual ~Field();
	//Getters
	bool isMandatory();
	bool isPolyvalent();
	DataType* getDataType();
	
	//Setters
	void setIsMandatory(bool isMandatory);
	void setIsPolyvalent(bool isPolyvalent);
	void setDataType(DataType* aDataType);
	
	//Otros metodos
	bool validate();
	int serialize(char** result);
	
};

#endif /*FIELD_H_*/
