#ifndef METADATABLOCK_H_
#define METADATABLOCK_H_

class MetadataBlock
{
public:
	MetadataBlock();
	virtual ~MetadataBlock(void);
	void load(char* blockContent);
	char* save();

	//Completar con...
	//PrimaryFieldType
	//SecondaryFieldTypes
	//Etc

	
	
	//Las propiedades blockSize, blockCount y fileSize est�n en la clase BlockStructuredFile


};

#endif /*METADATABLOCK_H_*/