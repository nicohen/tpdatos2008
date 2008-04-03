#include "StatementParser.h"

using namespace Parsing;
StatementParser::StatementParser(Parsing::ITokenizer* tokenizer,OutPutter* outputter)
{
	this->_statementCount=0;
	this->_tokenizer=tokenizer;
	this->_outPutter=outputter;
}

void StatementParser::parseFields(CreateStatement* statement){
	Parsing::Token* token =	NULL;
	DEBUG("Inicio del parseo de los campos\n");
	
		
	// PARSEO EL CORCHETE
	printf("PARSEO EL \"[\"\n");
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba \"[\" pero vino \"%s\".\n",token->getContent());		
	}else{
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se encontró \"[\".\n");
	}
	
	
	/*
	 mientras no se encuentre ]
	 si hay algo como int, string o |
	 crear un field 
	 (parseType)parsear los tipos
	 	si se encontro un int -> return inttype
	 	si se encontro un string -> return string
	 	si se encontro un | -> return structureType
	 
	 */
	
	token =	_tokenizer->getNextToken(false);
	while ((token!=NULL) && (strcmp(token->getContent(),"]")!=0)){
		if((strcmp(token->getContent(),",")==0)){
		}else{
			statement->addSecondaryField(this->parseField(token));
		}
		token =	_tokenizer->getNextToken(false);
	}
	return;
}

Field* StatementParser::parseField(Token* currentToken){
	Field* field=NULL;
	if (strcmp(currentToken->getContent(),"string")==0 || strcmp(currentToken->getContent(),"int") || strcmp(currentToken->getContent(),"|")){
		field= new Field();
		field->setDataType(this->parseType(currentToken));
		return field;
	}
	//TODO: LAnzar una excepcion
	return NULL;
}

DataType* StatementParser::parseType(Token* currentToken){
	if (strcmp(currentToken->getContent(),"string")==0){
		return new StringType();		
	}else if (strcmp(currentToken->getContent(),"int")==0){
		return new IntType();
	}if (strcmp(currentToken->getContent(),"|")==0){
		return new StructureType();		
		//TODO: llenar el StructureType
	}else{
		//TODO: LANZAR UN EXCEPCION
		printf("Se espera");
	}
}

/*Field* StatementParser::ParseField(){
	
}*/


int StatementParser::parseFileType(){
	int fileType;
	//TODO: llamar al debug
	printf("Inicio del parseo del tipo de archivo.\n");
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	printf("Inicio del parseo del tipo de archivo: Luego de obtener el token.\n");
	if ((token==NULL) || (token->getType()!=Parsing::ITokenizer::KEYWORD)){
		fileType= Statement::OTHER;
		//TODO: llamar al debug
		printf("1_No se encontró un tipo de archivo válido. Vino \"%s\".\n",token->getContent());
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
			//TODO: llamar al debug
			printf("2_No se encontró un tipo de archivo válido. Vino \"%s\".\n",token->getContent());
		}
	}
	//TODO: llamar al debug
	printf("Fin de parseo del tipo de archivo.\n");
	return fileType;
}

Statement* StatementParser::parseCreateStatement(){
	CreateStatement* createStatement=NULL;
	printf("Statement* StatementParser::parseCreateStatement(){\n");

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
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),";")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba ;. Vino: %s.\n",token->getContent());	
	}else{
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se encontró \";\".\n");
	}
	
	// PARSEO EL TIPO DE ARCHIVO
	createStatement->setFileType(parseFileType());
	//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
	printf("Se encontró el tipo de archivo.\n");
	
	/*
	// PARSEO EL CORCHETE
	printf("PARSEO EL \"[\"\n");
	token =	_tokenizer->getNextToken(false);
	if ((token==NULL)||(token->getType()!=Parsing::ITokenizer::DELIMITER)||(strcmp(token->getContent(),"[")!=0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba \"[\" pero vino \"%s\".\n",token->getContent());		
	}else{
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se encontró \"[\".\n");
	}
	*/
	
	//PARSEO LOS CAMPOS
	this->parseFields(createStatement);	
		
	printf("Fin parseo del create statement\n");
	this->_tokenizer->moveToNextLine(true);
	return createStatement;
}

Statement* StatementParser::parseInsertionStatement(){
	Parsing::Token* token =	NULL;
	Statement* statement=NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new InsertionStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseQueryStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new QueryStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseRemoveStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new RemoveStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseDeleteStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new DeleteStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseStatsStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new StatsStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::parseUpdateStatement(){
	Statement* statement=NULL;
	Parsing::Token* token =	NULL;
	// PARSEO NOMBRE DEL ARCHIVO DE DATOS
	printf("PARSEO NOMBRE DEL ARCHIVO DE DATOS\n");
	token =	_tokenizer->getNextToken(true);
	if((token==NULL) || (token->getType()!=Parsing::ITokenizer::STRING) || (strlen(token->getContent())==0)){
		//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
		printf("Se esperaba el nombre del archivo de datos (literal de cadena) pero vino: %s.",token->getContent());
	}else{
		statement=new UpdateStatement(token->getContent());		
	}
	return statement;
}

Statement* StatementParser::getNext(){
	Parsing::Token* token =	_tokenizer->getNextToken(false);
	printf("Statement* StatementParser::getNext(){\n.");
	printf("Primer token: %s\n.",token->getContent());
	if (token==NULL){
		printf("Primer token null\n.");
		//TODO: archivo vacio
		return NULL;
	}
	printf("VALIDA EL COMIENZO DEL STATEMENT\n.");
	try{
		// VALIDA EL COMIENZO DEL STATEMENT
		if ((token->getType()!=_tokenizer->KEYWORD)){
			
			//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
			printf("Se esperaba KEYWORD pero vino: %i\n. valor: \"%s\".\n",token->getType(),token->getContent());
			return NULL;
		}else{
			printf("Identificando el tipo de statement.\n");
			// IDENTIFICA EL TIPO DE STATEMENT Y DERIVO AL METODO CORRECTO
			if (strcmp(token->getContent(),"CREAR")==0){
				printf("Inicio del parseo de CREAR.\n");
				return parseCreateStatement();
			}
			if (strcmp(token->getContent(),"INGRESAR")==0){
				printf("Inicio del parseo de INGRESAR.\n");
				return parseInsertionStatement();
			}
			if (strcmp(token->getContent(),"CONSULTAR")==0){
				printf("Inicio del parseo de CONSULTAR.\n");
				return parseQueryStatement();
			}
			if (strcmp(token->getContent(),"QUITAR")==0){
				printf("Inicio del parseo de QUITAR.\n");
				return parseRemoveStatement();
			}
			if (strcmp(token->getContent(),"ELIMINAR")==0){
				printf("Inicio del parseo de ELIMINAR.\n");
				return parseDeleteStatement();
			}
			if (strcmp(token->getContent(),"ESTADISTICA")==0){
				printf("Inicio del parseo de ESTADISTICA.\n");
				return parseStatsStatement();
			}
			if (strcmp(token->getContent(),"FINALIZAR")==0){
				printf("Inicio del parseo de FINALIZAR.\n");
				throw new KillDaemonException();
			}
			if (strcmp(token->getContent(),"ACTUALIZAR")==0){
				printf("Inicio del parseo de ACTUALIZAR.\n");
				return parseUpdateStatement();
			}
			throw new StatementParserException("Tipo de statement desconocido\n");
			//TODO: loggear un error ERROR: "SE ESPERABA KEYWORD"
			printf("Tipo de statement desconocido\n.");			
			return NULL;
		}
	}catch(StatementParserException* e){
		//TODO: Llamar al tokenizer y decirle que vaya hasta el proximo \n
		printf("La linea es incorrecta. Se continuará parseando la proxima linea.\n");
		printf("Pasando a la linea siguiente.\n");
		this->_tokenizer->moveToNextLine(true);
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
