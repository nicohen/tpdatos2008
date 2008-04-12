#ifndef Metadata_H_
#define Metadata_H_

class Metadata
{
public:
	Metadata();
	virtual ~Metadata(void);
	void load(char* blockContent);
	char* save();

	//Completar con...
	//PrimaryFieldType
	//SecondaryFieldTypes
	//Etc

	
	
	//Las propiedades blockSize, blockCount y fileSize est�n en la clase BlockStructuredFile


};

#endif /*Metadata_H_*/