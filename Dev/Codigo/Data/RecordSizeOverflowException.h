#ifndef RECORDSIZEOVERFLOWEXCEPTION_H_
#define RECORDSIZEOVERFLOWEXCEPTION_H_

class RecordSizeOverflowException
{
public:
	RecordSizeOverflowException();
	virtual ~RecordSizeOverflowException();
	char* toString();
};

#endif /*RECORDSIZEOVERFLOWEXCEPTION_H_*/
