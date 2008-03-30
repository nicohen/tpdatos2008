#include "StatementParser.h"
#include "DataType.h"
#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"

using namespace Parsing;
StatementParser::StatementParser(Parsing::Tokenizer* tokenizer,OutPutter* outputter)
{
	this->_statementCount=0;
	this->_tokenizer=tokenizer;
	this->_outPutter=outputter;
}

Statement* StatementParser::getNext(){
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
