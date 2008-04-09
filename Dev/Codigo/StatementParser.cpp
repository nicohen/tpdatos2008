#include "StatementParser.h"
#include "IOException.h"
#include "ParserException.h"
#include "StringValue.h"
#include "IntValue.h"

using namespace Parsing;
StatementParser::StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter){
	this->_statementCount=0;
	this->_tokenizer=tokenizer;
	this->_outPutter=outputter;
}

StructureType* StatementParser::parseStructuredType(){
	StructureType* structuredType= new StructureType();
	DataType* dType;
	Token* token= _tokenizer->getNextToken(true);
	while ((token!=NULL)&&((token->getType()!=Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),"|")!=0))){		
		if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::KEYWORD)){
			delete structuredType;
			throw ParserException();
		}else{
			if (strcmp(token->getContent(),"string")==0){
				dType= new StringType();
				structuredType->addType(dType);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete structuredType;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete structuredType;
						throw ParserException();
					}
				}
			}else if (strcmp(token->getContent(),"int")==0){
				dType= new IntType();
				structuredType->addType(dType);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete structuredType;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete structuredType;
						throw ParserException();
					}
				}			
			}else{
				throw ParserException();
			}
			token =	_tokenizer->getNextToken(false);
		}
	}
	return structuredType;
}

void StatementParser::parseParameters(CreateStatement* statement){
	Parsing::Token* token =	NULL;
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		throw ParserException();
	}		
	token =	_tokenizer->getNextToken(false);
	if (token->getType()!=Parsing::ITokenizer::NUMBER){
		throw ParserException();	
	}
	statement->setDataBlockSize(atol(token->getContent()));
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
		throw ParserException();
	}
	if (strcmp(token->getContent(),",")!=0){
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	if (token->getType()!=Parsing::ITokenizer::NUMBER){
		throw ParserException();	
	}
	statement->setIndexSize(atol(token->getContent()));
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
		throw ParserException();
	}
	if (strcmp(token->getContent(),"]")!=0){
		throw ParserException();
	}
}

void StatementParser::parseIndex(CreateStatement* statement){
	Parsing::Token* token =	NULL;
	SecondaryIndex* sIndex = new SecondaryIndex();
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::NUMBER)){
		throw ParserException();
	}else{
		//HACER ALGO
	}
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"]")!=0)){
		throw ParserException();
	}
	statement->setSecondaryIndex(sIndex);		
}

void StatementParser::parseFields(CreateStatement* statement){
	Parsing::Token* token =	NULL;
	Field* field;
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		throw ParserException();		
	}
	
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL) && (strcmp(token->getContent(),"]")!=0)){
		if(token->getType()!=Parsing::ITokenizer::KEYWORD){
			if (strcmp(token->getContent(),"|")==0){
				field= new Field();
				try{
				field->setDataType(parseStructuredType());
				}catch(ParserException pe){
					delete field;
					throw pe;
				}
				statement->addSecondaryField(field);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"+")==0){
						field->setIsMandatory(true);
						token =	_tokenizer->getNextToken(false);
						if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
							delete field;
							throw ParserException();
						}else{
							if (strcmp(token->getContent(),"]")==0){
								break;
							}else if (strcmp(token->getContent(),",")!=0){
								delete field;
							throw ParserException();
							}
						}
					}else if (strcmp(token->getContent(),"*")==0){
						field->setIsPolyvalent(true);
						token =	_tokenizer->getNextToken(false);
						if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
							delete field;
							throw ParserException();
						}else{
							if (strcmp(token->getContent(),"]")==0){
								break;
							}else if (strcmp(token->getContent(),",")!=0){
								delete field;
							throw ParserException();
							}
						}
					}else if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete field;
						throw ParserException();
					}					
				}
			}
		}else{
			if (strcmp(token->getContent(),"string")==0){
				field= new Field();
				field->setDataType(new StringType());
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete field;
					throw ParserException();
					}
				}
			}else if (strcmp(token->getContent(),"int")==0){
				field= new Field();
				field->setDataType(new IntType());
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete field;
					throw ParserException();
					}
				}				
			}else{
				throw ParserException();
			}
		}
		token =	_tokenizer->getNextToken(false);			
	}
	return;
}

int StatementParser::parseFileType(){
	int fileType;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::KEYWORD)){
		throw ParserException();
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

StructureValue* StatementParser::parseStructuredValue(){
	StructureValue* structuredValue= new StructureValue();
	DataValue* dValue;
	Token* token= _tokenizer->getNextToken(true);
	while ((token!=NULL)&&((token->getType()!=Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),"|")!=0))){		
		if ((token==NULL)||!((token->getType()!=Parsing::ITokenizer::NUMBER)||(token->getType()!=Parsing::ITokenizer::STRING))){
			delete structuredValue;
			throw ParserException();
		}else{
			if (token->getType()==Parsing::ITokenizer::STRING){
				dValue= new StringValue(token->getContent());
				structuredValue->addValue(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete structuredValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete structuredValue;
						throw ParserException();
					}
				}
			}else if (token->getType()==Parsing::ITokenizer::NUMBER){
				dValue= new IntValue(atol(token->getContent()));
				structuredValue->addValue(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete structuredValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						delete structuredValue;
						throw ParserException();
					}
				}			
			}else{
				throw ParserException();
			}
			token =	_tokenizer->getNextToken(false);
		}
	}
	return structuredValue;
}

void StatementParser::parseValues(InsertionStatement* statement){
	DataValue* dValue;
	Parsing::Token* token =	NULL;
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL)&&(strcmp(token->getContent(),"]")!=0)){
		if((token->getType()!=Parsing::ITokenizer::NUMBER)&&(token->getType()!=Parsing::ITokenizer::STRING)){
			if (strcmp(token->getContent(),"|")==0){
				StructureValue* sValue;
				try{
				sValue= parseStructuredValue();
				}catch(ParserException pe){
					delete sValue;
					throw pe;
				}
				statement->addValue(sValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					delete sValue;
					throw ParserException();
				}else{
					 if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						throw ParserException();
					}					
				}
			}
		}else{
			if (token->getType()==Parsing::ITokenizer::STRING){
				dValue= new StringValue(token->getContent());
				statement->addValue(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						throw ParserException();
					}
				}
			}else if (token->getType()==Parsing::ITokenizer::NUMBER){
				dValue= new IntValue(atol(token->getContent()));
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						throw ParserException();
					}
				}
			}else{
				throw ParserException();
			}
		token =	_tokenizer->getNextToken(false);
		}	
	}
}

Statement* StatementParser::parseCreateStatement(){
	CreateStatement* createStatement=NULL;
	// PARSEO ESPACIO
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(strcmp(token->getContent()," ")!=0)){
		throw ParserException();
	}
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		throw ParserException();
	}else{
		createStatement=new CreateStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		delete createStatement; 
		throw ParserException();	
	}	
	// PARSEO EL TIPO DE ARCHIVO
	try{
		createStatement->setFileType(parseFileType());
	}catch(ParserException pe){
		delete createStatement; 
		throw ParserException();
	}
	//PARSEO LOS CAMPOS
	try{
		this->parseFields(createStatement);
	}catch(ParserException pe){
		delete createStatement; 
		throw ParserException();
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		delete createStatement; 
		throw ParserException();	
	}
	//PARSEO LOS PARAMETROS
	try{
		this->parseParameters(createStatement);
	}catch(ParserException pe){
		delete createStatement; 
		throw ParserException();
	}
	// PARSEO EL ";" o "\n"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||!((strcmp(token->getContent(),";")!=0)||(strcmp(token->getContent(),"\n")!=0))){
		delete createStatement; 
		throw ParserException();	
	}else{
		if (strcmp(token->getContent(),"\n")==0){
			return createStatement;			
		}
	}
	//PARSEO EL TIPO DE INDICE
	try{
		this->parseIndex(createStatement);
	}catch(ParserException pe){
		delete createStatement; 
		throw ParserException();
	}
	return createStatement;
}

Statement* StatementParser::parseInsertionStatement(){
	InsertionStatement* statement=NULL;
	// PARSEO ESPACIO
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(strcmp(token->getContent()," ")!=0)){
		throw ParserException();
	}
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		throw ParserException();
	}else{
		statement=new InsertionStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		delete statement; 
		throw ParserException();	
	}
	// PARCEO LOS VALORES
	try{
		this->parseValues(statement);
	}catch(ParserException pe){
		delete statement; 
		throw ParserException();
	}
	return statement;
}

Statement* StatementParser::parseQueryStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	//printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		//printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new QueryStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseRemoveStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	//printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		//printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new RemoveStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseDeleteStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	//printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		//printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new DeleteStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseStatsStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
//	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");////
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		//printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new StatsStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseUpdateStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		//printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new UpdateStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::getNext() {
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if (token==NULL){
		return NULL;
	}
	try{
		// VALIDA EL COMIENZO DEL STATEMENT
		if ((token->getType()!=_tokenizer->KEYWORD)){
			DEBUG("Se esperaba KEYWORD");
			return NULL;
		}else{
			// IDENTIFICA EL TIPO DE STATEMENT Y DERIVO AL METODO CORRECTO
			if (strcmp(token->getContent(),"CREAR")==0){
				DEBUG("Inicio del parseo de CREAR.\n");
				return parseCreateStatement();
			}
			if (strcmp(token->getContent(),"INGRESAR")==0){
				DEBUG("Inicio del parseo de INGRESAR.\n");
				return parseInsertionStatement();
			}
			if (strcmp(token->getContent(),"CONSULTAR")==0){
				DEBUG("Inicio del parseo de CONSULTAR.\n");
				return parseQueryStatement();
			}
			if (strcmp(token->getContent(),"QUITAR")==0){
				DEBUG("Inicio del parseo de QUITAR.\n");
				return parseRemoveStatement();
			}
			if (strcmp(token->getContent(),"ELIMINAR")==0){
				DEBUG("Inicio del parseo de ELIMINAR.\n");
				return parseDeleteStatement();
			}
			if (strcmp(token->getContent(),"ESTADISTICA")==0){
				DEBUG("Inicio del parseo de ESTADISTICA.\n");
				return parseStatsStatement();
			}
			if (strcmp(token->getContent(),"FINALIZAR")==0){
				DEBUG("Inicio del parseo de FINALIZAR.\n");
				throw new KillDaemonException();
			}
			if (strcmp(token->getContent(),"ACTUALIZAR")==0){
				DEBUG("Inicio del parseo de ACTUALIZAR.\n");
				return parseUpdateStatement();
			}
			throw new StatementParserException("Tipo de statement desconocido\n");
			//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
			DEBUG("Tipo de statement desconocido\n.");			
			return NULL;
		}
	}catch(StatementParserException* e){
		//TODO: Llamar al tokenizer y decirle que vaya hasta el proximo \n
		DEBUG("La linea es incorrecta. Se continuará parseando la proxima linea.\n");
		this->_tokenizer->moveToNextLine(true);
		
	}
	return NULL;
	
	
	
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
