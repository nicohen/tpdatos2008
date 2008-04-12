#ifndef RECORD_H_
#define RECORD_H_

/*
 * Contiene los datos de un registro
 * */
class Record
{
public:
	Record();
	virtual ~Record();
	char* toString();
};

#endif /*RECORD_H_*/
