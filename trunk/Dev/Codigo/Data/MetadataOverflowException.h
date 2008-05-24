#ifndef METADATAOVERFLOWEXCEPTION_H_
#define METADATAOVERFLOWEXCEPTION_H_

class MetadataOverflowException
{
public:
	MetadataOverflowException();
	virtual ~MetadataOverflowException();
	char* toString();
};

#endif /*METADATAOVERFLOWEXCEPTION_H_*/
