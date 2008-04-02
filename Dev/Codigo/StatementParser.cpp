#include "StatementParser.h"
#include "DataType.h"
#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"
#include "Token.h"

using namespace Parsing;
StatementParser::StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter)
{
	this->_statementCount=0;
	this->_tokenizer=tokenizer;
	this->_outPutter=outputter;
}

void StatementParser::parseFields(CreateStatement* statement){
	Field *field=NULL;
	
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER) || (strcmp(token->getContent(),"[")==0)){
		return;
	}
	//ya no hace falta eliminar tokens. Se eliminan solos
	//delete token;
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL)&&(token->getType()!=Parsing::ITokenizer::DELIMITER) || (strcmp(token->getContent(),"]")!=0)){
		if (token->getType()==Parsing::ITokenizer::KEYWORD){
			if (strcmp(token->getContent(),"string")==0){
				field= new Field();
				field->setDataType(new StringType());
				statement->addSecondaryField(field);
			}else if (strcmp(token->getContent(),"int")==0){
				field= new Field();
				field->setDataType(new IntType());
				statement->addSecondaryField(field);
			}else{
				// Y ACA?
			}
		}else{
		}
	}
	return;
}

int StatementParser::parseFileType(){
	int fileType;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::KEYWORD)){
		fileType= Statement::OTHER;
	}else{
		if (strcmp(token->getContent(),"secuencial")==0){ 
			fileType=Statement::SECUENCIAL;
		}else if (strcmp(token->getContent(),"hash")==0){ 
			fileType=Statement::HASH;
		}else if (strcmp(token->getContent(),"indexado")==0){ 
			fileType=Statement::INDEXADO;
		}else if (strcmp(token->getContent(),"secIndexado")==0){ 
			fileType=Statement::SECINDEXADO;
		}else{
			fileType=Statement::OTHER;
		}
	}
	return fileType;
}

Statement* StatementParser::parseCreateStatemet(){
	CreateStatement* createStatement=NULL;
	printf("Statement* StatementParser::parseCreateStatemet(){\n");

	// PARSEO ESPACIO
	printf("PARSEO ESPACIO\n");
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(strcmp(token->getContent()," ")!=0)){
		//TODO: loggear un error ERROR: "Se esperaba espacio"
		printf("Se esperaba espacio.");
	}
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		createStatement=new CreateStatement(token->getContent());		
	}
	// PARSEO EL ";"
	printf("PARSEO EL \";\"\n");
	token =	_tokenizer->getNextToken(true);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba ;.\n");	
	}
	
	// PARSEO EL TIPO DE ARCHIVO
	createStatement->setFileType(parseFileType());
	
	// PARSEO EL CORCHETE
	printf("PARSEO EL \"[\"\n");
	token =	_tokenizer->getNextToken(true);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba \"[\";.\n");		
	}
	
	// PARSEO LOS CAMPOS
	token =	_tokenizer->getNextToken(true);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba \"[\";.\n");		
	}
		
		
	printf("Fin parseo del create statement\n");
	return createStatement;
}

Statement* StatementParser::parseAddStatemet(){

}

Statement* StatementParser::parseConsultStatemet(){

}

Statement* StatementParser::parseRemoveStatemet(){

}

Statement* StatementParser::parseDeleteStatemet(){

}

Statement* StatementParser::parseStatsStatemet(){

}

Statement* StatementParser::parseEndStatemet(){

}

Statement* StatementParser::parseActualizeStatemet(){

}
	
Statement* StatementParser::getNext(){
	printf("Statement* StatementParser::getNext(){\n.");
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	printf("Primer token: %s\n.",token->getContent());
	if (token==NULL){
		printf("Primer token null\n.");
		//TODO: archivo vacio
		return NULL;
	}
	printf("VALIDA EL COMIENZO DEL STATEMENT\n.");
	// VALIDA EL COMIENZO DEL STATEMENT
	if ((token->getType()!=_tokenizer->KEYWORD)){
		
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba KEYWORD pero vino: %i\n. valor: \"%s\".\n",token->getType(),token->getContent());
		return NULL;
		/*do{
			token= _tokenizer->getNextToken(false);
		}while ((token!=NULL) && (token->getType()!=_tokenizer->DELIMITER) && (strcmp(token->getContent(),"\n")));
		return getNext();*/
	}else{
		printf("Identificando el tipo de statement.\n");
		// IDENTIFICA EL TIPO DE STATEMENT Y DERIVO AL METODO CORRECTO
		if (strcmp(token->getContent(),"CREAR")==0){
			return parseCreateStatemet();
		}
		if (strcmp(token->getContent(),"INGRESAR")==0){
			printf("__INGRESAR\n;");
			return parseAddStatemet();
		}
		if (strcmp(token->getContent(),"CONSULTAR")==0){
			return parseConsultStatemet();
		}
		if (strcmp(token->getContent(),"QUITAR")==0){
			return parseRemoveStatemet();
		}
		if (strcmp(token->getContent(),"ELIMINAR")==0){
			return parseDeleteStatemet();
		}
		if (strcmp(token->getContent(),"ESTADISTICA")==0){
			return parseStatsStatemet();
		}
		if (strcmp(token->getContent(),"FINALIZAR")==0){
			return parseEndStatemet();
		}
		if (strcmp(token->getContent(),"ACTUALIZAR")==0){
			return parseActualizeStatemet();
		}
		printf("Tipo de statement desconocido\n.");
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		return NULL;
	}
	//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
	
	/*CreateStatement de ejemplo*********************/
	/*
	CreateStatement* vvCreateStatement=NULL;
	SecondaryIndex* vvSecondaryIndex=NULL;
	Field* vvSecondaryField=NULL;
	IntType* intType=NULL;
	StringType* stringType=NULL;
	StructureType* structureType=NULL;
	
	vvCreateStatement=new CreateStatement("datos.dat");	
	vvCreateStatement->setFileType(1);
	vvCreateStatement->setDataBlockSize(30);
	vvCreateStatement->setIndexSize(55);
	
	//Creo y seteo un indice secundario
	vvSecondaryIndex=new SecondaryIndex();
	vvCreateStatement->setSecondaryIndex(vvSecondaryIndex);//Testear aparte	
	
	//Creo y agrego un campo secundario
	vvSecondaryField=new Field();
	
	vvSecondaryField->setIsMandatory(true);
	vvSecondaryField->setIsPolyvalent(true);
	
	intType=new IntType();	
	stringType=new StringType();	
	structureType=new StructureType();
	structureType->addType(intType);
	structureType->addType(stringType);
	
	vvCreateStatement->addSecondaryField(vvSecondaryField);	
	
	if(this->_statementCount<3){
		this->_statementCount++;
		return vvCreateStatement;
	}else{
		return 0;		
	}
	*/
}

StatementParser::~StatementParser()
{
}
