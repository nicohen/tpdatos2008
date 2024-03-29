#include "StatementParser.h"
#include "IOException.h"
#include "ParserException.h"
#include "StringValue.h"
#include "IntValue.h"
#include <stdlib.h>

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
			DEBUG_CONDITIONAL("Se esperaba el tipo de dato en lugar de:");
			DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
			delete structuredType;
			throw ParserException();
		}else{
			if (strcmp(token->getContent(),"string")==0){
				dType= new StringType();
				structuredType->addType(dType);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete structuredType;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete structuredType;
						throw ParserException();
					}
				}
			}else if (strcmp(token->getContent(),"int")==0){
				dType= new IntType();
				structuredType->addType(dType);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete structuredType;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
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
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}		
	token =	_tokenizer->getNextToken(false);
	if (token->getType()!=Parsing::ITokenizer::NUMBER){
		DEBUG_CONDITIONAL("Se esperaba un número en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();	
	}
	statement->setDataBlockSize(atol(token->getContent()));
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
		DEBUG_CONDITIONAL("Se esperaba ',' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	if (strcmp(token->getContent(),",")!=0){
		DEBUG_CONDITIONAL("Se esperaba ',' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	if (token->getType()!=Parsing::ITokenizer::NUMBER){
		DEBUG_CONDITIONAL("Se esperaba un número en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	statement->setIndexSize(atol(token->getContent()));
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
		DEBUG_CONDITIONAL("Se esperaba ']' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	if (strcmp(token->getContent(),"]")!=0){
		DEBUG_CONDITIONAL("Se esperaba ']' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
}

void StatementParser::parseIndex(CreateStatement* statement){
	Parsing::Token* token =	NULL;
	int fieldNumber;
	int indexType = this->parseFileType();
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::NUMBER)){
		DEBUG_CONDITIONAL("Se esperaba un numero en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		fieldNumber= atol(token->getContent());
	}
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"]")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ']' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	statement->setSecondaryIndex(new SecondaryIndex(indexType,fieldNumber));
}

std::vector<Field*>* StatementParser::parseFields(){
	std::vector<Field*>* list = new std::vector<Field*>(); 
	Parsing::Token* token =	NULL;
	Field* field;
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
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
					throw ParserException();
				}
				list->push_back(field);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba '+', '*', ',' o '|' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"+")==0){
						field->setIsMandatory(true);
						field->setIsPolyvalent(true);
						token =	_tokenizer->getNextToken(false);
						if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
							DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
							DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
							delete field;
							throw ParserException();
						}else{
							if (strcmp(token->getContent(),"]")==0){
								break;
							}else if (strcmp(token->getContent(),",")!=0){
								DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
								DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
								delete field;
								throw ParserException();
							}
						}
					}else if (strcmp(token->getContent(),"*")==0){
						field->setIsMandatory(false);
						field->setIsPolyvalent(true);
						token =	_tokenizer->getNextToken(false);
						if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
							DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
							DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
							delete field;
							throw ParserException();
						}else{
							if (strcmp(token->getContent(),"]")==0){
								break;
							}else if (strcmp(token->getContent(),",")!=0){
								DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
								DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
								delete field;
							throw ParserException();
							}
						}
					}else if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete field;
						throw ParserException();
					}					
				}
			}
		}else{
			if (strcmp(token->getContent(),"string")==0){
				field= new Field();
				field->setDataType(new StringType());
				field->setIsMandatory(true);
				field->setIsPolyvalent(false);
				list->push_back(field);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete field;
					throw ParserException();
					}
				}
			}else if (strcmp(token->getContent(),"int")==0){
				field= new Field();
				field->setDataType(new IntType());
				field->setIsMandatory(true);
				field->setIsPolyvalent(false);
				list->push_back(field);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete field;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o '|' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete field;
						throw ParserException();
					}
				}				
			}else{
				DEBUG_CONDITIONAL("Se esperaba un tipo de datos en lugar de:");
				DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
				throw ParserException();
			}
		}
		token =	_tokenizer->getNextToken(false);		
	}
	return list;
}

int StatementParser::parseFileType(){
	int fileType;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if ((token!=NULL) && (strcmp(token->getContent(),"\n")==0)){
		throw StatementParserException("No lleva indice secundario");
	}
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::KEYWORD)){
		DEBUG_CONDITIONAL("Se esperaba el tipo de organización en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
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
			DEBUG_CONDITIONAL("Se esperaba un valor numérico o un string en lugar de:");
			DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
			delete structuredValue;
			throw ParserException();
		}else{
			if (token->getType()==Parsing::ITokenizer::STRING){
				dValue= new StringValue(token->getContent());
				structuredValue->addValue(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba '|' o ',' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete structuredValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba '|' o ',' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete structuredValue;
						throw ParserException();
					}
				}
			}else if (token->getType()==Parsing::ITokenizer::NUMBER){
				dValue= new IntValue(atol(token->getContent()));
				structuredValue->addValue(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba '|' o ',' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete structuredValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"|")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba '|' o ',' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete structuredValue;
						throw ParserException();
					}
				}			
			}else{
				DEBUG_CONDITIONAL("Se esperaba un valor numérico o un string en lugar de:");
				DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
				throw ParserException();
			}
			token =	_tokenizer->getNextToken(false);
		}
	}
	return structuredValue;
}

std::vector<DataValue*>* StatementParser::parseValues(){
	std::vector<DataValue*>* list= new std::vector<DataValue*>();
	DataValue* dValue;
	Parsing::Token* token =	NULL;
	// PARSEO EL CORCHETE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL)&&(strcmp(token->getContent(),"]")!=0)){
		if((token->getType()!=Parsing::ITokenizer::NUMBER)&&(token->getType()!=Parsing::ITokenizer::STRING)){
			if (strcmp(token->getContent(),"|")==0){
				try{
				dValue= parseStructuredValue();
				}catch(ParserException pe){
					delete dValue;
					throw pe;
				}
				list->push_back(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete dValue;
					throw ParserException();
				}else{
					 if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete dValue;
						throw ParserException();
					}					
				}
				token =	_tokenizer->getNextToken(false);
			}
		}else{
			if (token->getType()==Parsing::ITokenizer::STRING){
				dValue= new StringValue(token->getContent());
				list->push_back(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete dValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete dValue;
						throw ParserException();
					}
				}
			}else if (token->getType()==Parsing::ITokenizer::NUMBER){
				dValue= new IntValue(atol(token->getContent()));
				list->push_back(dValue);
				token =	_tokenizer->getNextToken(false);
				if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::DELIMITER)){
					DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
					DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
					delete dValue;
					throw ParserException();
				}else{
					if (strcmp(token->getContent(),"]")==0){
						break;
					}else if (strcmp(token->getContent(),",")!=0){
						DEBUG_CONDITIONAL("Se esperaba ',' o ']' en lugar de:");
						DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
						delete dValue;
						throw ParserException();
					}
				}
			}else{
				DEBUG_CONDITIONAL("Se esperaba algun valor en lugar de:");
				DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
				throw ParserException();
			}
		token =	_tokenizer->getNextToken(false);
		}
	}
	return list;	
}

Statement* StatementParser::parseCreateStatement(){
	CreateStatement* createStatement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		createStatement=new CreateStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		delete createStatement; 
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}	
	// PARSEO EL TIPO DE ARCHIVO
	try{
		createStatement->setFileType(parseFileType());
	}catch(StatementParserException pe){
		delete createStatement; 
		throw ParserException();
	}
	//PARSEO LOS CAMPOS
	try{
		createStatement->addSecondaryFields(this->parseFields());		
	}catch(ParserException pe){
		delete createStatement;
		throw ParserException();
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		delete createStatement;
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
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
		DEBUG_CONDITIONAL("Se esperaba ';' o fin de linea en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete createStatement; 
		throw ParserException();	
	}else{
		if (strcmp(token->getContent(),"\n")==0){
			DEBUG_CONDITIONAL("Fin de parseo CREAR correctamente.");
			return createStatement;			
		}
	}
	//PARSEO EL TIPO DE INDICE
	try{
		this->parseIndex(createStatement);
	}catch(ParserException pe){
		delete createStatement; 
		throw ParserException();
	}catch(StatementParserException pe){
		DEBUG_CONDITIONAL("Fin de parseo CREAR correctamente.");
		return createStatement;
	}
	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo CREAR correctamente.");
		return createStatement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete createStatement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo CREAR correctamente.");
	return createStatement;
}

Statement* StatementParser::parseInsertionStatement(){
	InsertionStatement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new InsertionStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();	
	}
	// PARCEO LOS VALORES
	try{
		statement->addValues(this->parseValues());
	}catch(ParserException pe){
		delete statement; 
		throw ParserException();
	}
	
	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo INGRESAR correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo INGRESAR correctamente.");
	return statement;
}

Statement* StatementParser::parseQueryStatement(){
	QueryStatement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new QueryStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();	
	}
	
	//PARCEO "["
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	// PARCEO LA CLAVE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::NUMBER)){
		DEBUG_CONDITIONAL("Se esperaba un valor numerico en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	statement->setFieldNumber(atol(token->getContent()));
	//PARCEO ","
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),",")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ',' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	//PARCEO EL VALOR
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||!((token->getType()==Parsing::ITokenizer::NUMBER)||(token->getType()==Parsing::ITokenizer::STRING)||(strcmp(token->getContent(),"|")==0))){
		DEBUG_CONDITIONAL("Se esperaba valor en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	if (token->getType()==Parsing::ITokenizer::NUMBER){
		statement->setValue(new IntValue(atol(token->getContent())));
	}else if (token->getType()==Parsing::ITokenizer::STRING){
		statement->setValue(new StringValue(token->getContent()));
	}else{
		try{
			statement->setValue(parseStructuredValue());
		}catch(ParserException ex){
			delete statement;
			throw ex;
		}
	}
	
	//PARCEO "]"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"]")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ']' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo CONSULTAR correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo CONSULTAR correctamente.");
	return statement;
}

Statement* StatementParser::parseRemoveStatement(){
	RemoveStatement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new RemoveStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();	
	}
	
	//PARCEO "["
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		DEBUG_CONDITIONAL("Se esperaba '[' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	// PARCEO LA CLAVE
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::NUMBER)){
		DEBUG_CONDITIONAL("Se esperaba un valor numerico en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	statement->setFieldNumber(atol(token->getContent()));
	//PARCEO ","
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),",")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ',' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	//PARCEO EL VALOR
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||!((token->getType()==Parsing::ITokenizer::NUMBER)||(token->getType()==Parsing::ITokenizer::STRING)||(strcmp(token->getContent(),"|")==0))){
		DEBUG_CONDITIONAL("Se esperaba valor en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	if (token->getType()==Parsing::ITokenizer::NUMBER){
		statement->setValue(new IntValue(atol(token->getContent())));
	}else if (token->getType()==Parsing::ITokenizer::STRING){
		statement->setValue(new StringValue(token->getContent()));
	}else{
		try{
			statement->setValue(parseStructuredValue());
		}catch(ParserException ex){
			delete statement;
			throw ex;
		}
	}
	
	//PARCEO "]"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"]")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ']' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	
	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo QUITAR correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo QUITAR correctamente.");
	return statement;
}

Statement* StatementParser::parseDeleteStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new DeleteStatement(token->getContent());
	}

	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo ELIMINAR correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo ELIMINAR correctamente.");
	return statement;
}

Statement* StatementParser::parseStatsStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new StatsStatement(token->getContent());
	}

	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo ESTADISTICA correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo ESTADISTICA correctamente.");
	return statement;
}

Statement* StatementParser::parseUpdateStatement(){
	UpdateStatement* statement=NULL;
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		DEBUG_CONDITIONAL("Se esperaba el nombre del archivo de datos, se recibió:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		throw ParserException();
	}else{
		statement=new UpdateStatement(token->getContent());
	}
	// PARSEO EL ";"
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();	
	}
	// PARCEO LOS VALORES
	try{
		statement->addValues(this->parseValues());
	}catch(ParserException pe){
		delete statement; 
		throw ParserException();
	}
	
	token =	_tokenizer->getNextToken(false);
	if ((token->getType()==Parsing::ITokenizer::DELIMITER)&&(strcmp(token->getContent(),";")==0)){
		_tokenizer->moveToNextLine();
		DEBUG_CONDITIONAL("Fin de parseo ACTUALIZAR correctamente.");
		return statement;
	}
	if ((token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"\n")!=0)){
		DEBUG_CONDITIONAL("Se esperaba ';' fin de linead en lugar de:");
		DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
		delete statement; 
		throw ParserException();
	}
	DEBUG_CONDITIONAL("Fin de parseo ACTUALIZAR correctamente.");
	return statement;
}

Statement* StatementParser::getNext(){
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	Statement* statement= NULL;
	char* statementType;
	string buffer;

	// VALIDA EL COMIENZO DEL STATEMENT
	while ((token!=NULL)&&(strcmp(token->getContent(),"\n")==0)){
		token= _tokenizer->getNextToken(false);
	}
	
	if ((token!=NULL)&&(token->getType()!=Parsing::ITokenizer::KEYWORD)){
		DEBUG_CONDITIONAL("Se esperaba KEYWORD en lugar de:");
		DEBUG_CONDITIONAL(token->getContent());
		buffer.append("Sentecia desconocida: ");
		buffer.append(token->getContent());
		_tokenizer->moveToNextLine();
		throw new StatementParserException(buffer.c_str());
	}
	
	if (token==NULL){
		return NULL;
	}
	statementType= cloneStr(token->getContent());
	try{
		// IDENTIFICA EL TIPO DE STATEMENT Y DERIVO AL METODO CORRECTO
		if (strcmp(token->getContent(),"CREAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de CREAR.");
			statement= parseCreateStatement();
		}
		if (strcmp(token->getContent(),"INGRESAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de INGRESAR.");
			statement= parseInsertionStatement();
		}
		if (strcmp(token->getContent(),"CONSULTA")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de CONSULTA.");
			statement= parseQueryStatement();
		}
		if (strcmp(token->getContent(),"QUITAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de QUITAR.");
			statement= parseRemoveStatement();
		}
		if (strcmp(token->getContent(),"ELIMINAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de ELIMINAR.");
			statement= parseDeleteStatement();
		}
		if (strcmp(token->getContent(),"ESTADISTICA")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de ESTADISTICA.");
			statement= parseStatsStatement();
		}
		if (strcmp(token->getContent(),"FINALIZAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de FINALIZAR.");
			free(statementType);
			throw new KillDaemonException();
		}
		if (strcmp(token->getContent(),"ACTUALIZAR")==0){
			DEBUG_CONDITIONAL("Inicio del parseo de ACTUALIZAR.");
			statement= parseUpdateStatement();
		}
		free(statementType);
		return statement;
	}catch(StatementParserException* e){
		DEBUG_CONDITIONAL("La linea es incorrecta. Se continuará parseando la proxima linea.\n");
		if (strcmp(_tokenizer->getLastToken()->getContent(),"\n")!=0){
			_tokenizer->moveToNextLine();
		}
		buffer.append("Error al parsear sentecia ");
		buffer.append(statementType);
		free(statementType);
		throw new StatementParserException(buffer.c_str());
	}catch(ParserException e1){
		//TODO: Llamar al tokenizer y decirle que vaya hasta el proximo \n
		DEBUG_CONDITIONAL("La linea es incorrecta. Se continuará parseando la proxima linea.\n");
		if (strcmp(_tokenizer->getLastToken()->getContent(),"\n")!=0){
			_tokenizer->moveToNextLine();
		}
		buffer.append("Error al parsear sentecia ");
		buffer.append(statementType);
		free(statementType);
		throw new StatementParserException(buffer.c_str());
	}
	DEBUG_CONDITIONAL("Tipo de statement desconocido:");
	DEBUG_CONDITIONAL((token==NULL)?"fin de archivo":token->getContent());
	if (strcmp(_tokenizer->getLastToken()->getContent(),"\n")!=0){
		_tokenizer->moveToNextLine();
	}
	buffer.append("Sentecia desconocida: ");
	buffer.append(statementType);
	free(statementType);
	throw new StatementParserException(buffer.c_str());
}

StatementParser::~StatementParser(){
}
