#pragma once

class Metadata
{
public:
	Metadata();
	virtual ~Metadata(void);
	void load(char* blockContent);
	char* save();


	//Las propiedades blockSize, blockCount y fileSize est�n en la clase BlockStructuredFile
	//
	//PrimaryFieldType
	//SecondaryFieldTypes
	//Etc



};
