#include "DataValue.h"

DataValue::DataValue()
{
}

DataValue::~DataValue()
{
}


bool DataValue::equals(DataValue* other){
	return this->getType()->getUniqueIdentifier()==other->getType()->getUniqueIdentifier();
}

T_STRING_LENGHT DataValue::getSerializationFullSize(){
	return sizeof(T_STRING_LENGHT)+this->getSerializationSize();
}


//Lee primero el largo, luego llama al deserializar del valor particular
char* DataValue::deserialize(char* data){
	T_STRING_LENGHT lenght;
	memcpy(&lenght,data,sizeof(T_STRING_LENGHT));	
	this->deserializeValue(data+sizeof(T_STRING_LENGHT),lenght);
	return data+sizeof(T_STRING_LENGHT)+lenght;
}

//Guarda: Largo del valor, serialización particular
char* DataValue::serialize(){
	char* data;
	T_STRING_LENGHT lenght;
	//obtengo el largo del valor que voy a serializar
	lenght=this->getSerializationSize();
	//reservo memoria para guardar
	data=(char*)malloc(sizeof(T_STRING_LENGHT)+lenght);
	//copio la longitud del valor dentro de la cadena de serialización
	memcpy(data,(char*)&lenght,sizeof(T_STRING_LENGHT));
	//llamo al serializar particular	
	this->serializeTo(data+sizeof(T_STRING_LENGHT));
	return data;
}
