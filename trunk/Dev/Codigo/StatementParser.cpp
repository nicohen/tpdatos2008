#include "StatementParser.h"
#include "DataType.h"
#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"
#include "Token.h"

using namespace Parsing;
StatementParser::StatementParser(Parsing::Tokenizer* tokenizer,OutPutter* outputter)
{
	this->_statementCount=0;
	this->_tokenizer=tokenizer;
	this->_outPutter=outputter;
}

vector<Field*>* StatementParser::parseFields(){
	Field *field=NULL;
	std::vector<Field*>* fields=new vector<Field*>();
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::Tokenizer::DELIMITER) || (strcmp(token->getContent(),"[")==0)){
		delete fields;
		return NULL;
	}
	delete token;
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL)&&(token->getType()!=Parsing::Tokenizer::DELIMITER) || (strcmp(token->getContent(),"]")!=0)){
		if (token->getType()==Parsing::Tokenizer::KEYWORD){
			if (strcmp(token->getContent(),"string")==0){
				field= new Field();
				field->setDataType(new StringType());
				fields->push_back(field);
			}else if (strcmp(token->getContent(),"int")==0){
				field= new Field();
				field->setDataType(new IntType());
				fields->push_back(field);
			}else{
				// Y ACA?
			}
		}else{
		}
	}
	return fields;
}

int StatementParser::parseFileType(void){
	int fileType;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::Tokenizer::KEYWORD)){
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
	delete token;
	return fileType;
}

Statement* StatementParser::parseCreateStatemet(){
	CreateStatement* vvCreateStatement=NULL;
	char* fileName;
	int fileType;
	// VALIDO ESPACIO
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(strcmp(token->getContent()," ")!=0)){
		// Y ACA?
	}
	// VALIDO NOMBRE DEL ARCHIVO DE DATOS
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::Tokenizer::STRING) || (strlen(token->getContent())==0)){
		// Y ACA?
	}else{
		fileName= cloneStr(token->getContent());
	}
	// VALIDO EL ;
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::Tokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		free(fileName);
		// Y ACA?
	}
	// VALIDO EL TIPO DE DATO
	fileType = parseFileType();
	if (fileType==0){
		free(fileName);
		// Y ACA?
	}
	return vvCreateStatement;
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
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if (token==NULL){
		return NULL;
	}
	// VALIDA EL COMIENZO DEL STATEMENT
	if ((token->getType()!=_tokenizer->KEYWORD)){
		do{
			delete token;
			token= _tokenizer->getNextToken(false);
		}while ((token!=NULL) && (token->getType()!=_tokenizer->DELIMITER) && (strcmp(token->getContent(),"\n")));
		delete token;
		// BUSCA EL SIGUIENTE SIN ERRORES
		return getNext();
	}
	// IDENTIFICA EL TIPO DE STATEMENT Y DERIBO AL METODO CORRECTO
	if (strcmp(token->getContent(),"CREAR")){
		return parseCreateStatemet();
	}
	if (strcmp(token->getContent(),"INGRESAR")){
		return parseAddStatemet();
	}
	if (strcmp(token->getContent(),"CONSULTAR")){
		return parseConsultStatemet();
	}
	if (strcmp(token->getContent(),"QUITAR")){
		return parseRemoveStatemet();
	}
	if (strcmp(token->getContent(),"ELIMINAR")){
		return parseDeleteStatemet();
	}
	if (strcmp(token->getContent(),"ESTADISTICA")){
		return parseStatsStatemet();
	}
	if (strcmp(token->getContent(),"FINALIZAR")){
		return parseEndStatemet();
	}
	if (strcmp(token->getContent(),"ACTUALIZAR")){
		return parseActualizeStatemet();
	}
	/***************************************/
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
	
	if(this->_statementCount>3){
		this->_statementCount++;
		return vvCreateStatement;
	}else{
		return 0;		
	}
}

StatementParser::~StatementParser()
{
}
