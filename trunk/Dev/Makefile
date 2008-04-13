#Esto es un comentario

#Es la ruta para llegar a los archivos que estan en el codigo
CODE_PATH:= Codigo/
DATA_PATH:= $(CODE_PATH)Data/
TEST_PATH:= $(CODE_PATH)TestingFramework/

#TARGET es una variable que se va a usar mas abajo. Indica el nombre del archivo que se va a ejecutar 
TARGET:= AlmacenX

#Una variable que no se usa
#OBJ =


 
#Archivos que estan en producción       
				
GLOBAL_CPP:=	$(CODE_PATH)BufferedDataManager.cpp\
	$(DATA_PATH)Block.cpp\
	$(CODE_PATH)CreateStatement.cpp\
	$(CODE_PATH)DataFile.cpp\
	$(CODE_PATH)DataManager.cpp\
	$(CODE_PATH)DataType.cpp\
	$(CODE_PATH)DataValue.cpp\
	$(CODE_PATH)DeleteStatement.cpp\
	$(CODE_PATH)Demon.cpp\
	$(CODE_PATH)EndStatement.cpp\
	$(CODE_PATH)Field.cpp\
	$(CODE_PATH)FileManager.cpp\
	$(CODE_PATH)FileInfo.cpp\
	$(CODE_PATH)InsertionStatement.cpp\
	$(CODE_PATH)IntType.cpp\
	$(CODE_PATH)IntValue.cpp\
	$(CODE_PATH)IOException.cpp\
	$(CODE_PATH)ITokenizer.cpp\
	$(CODE_PATH)KillDaemonException.cpp\
	$(CODE_PATH)OutPutter.cpp\
	$(CODE_PATH)ParserException.cpp\
	$(DATA_PATH)RecordsBlock.cpp\
	$(CODE_PATH)RemoveStatement.cpp\
	$(CODE_PATH)SecondaryIndex.cpp\
	$(CODE_PATH)Statement.cpp\
	$(CODE_PATH)StatementParser.cpp\
	$(CODE_PATH)StatementParserException.cpp\
	$(CODE_PATH)StatementResult.cpp\
	$(CODE_PATH)StatsStatement.cpp\
	$(CODE_PATH)StringType.cpp\
	$(CODE_PATH)StringValue.cpp\
	$(CODE_PATH)StructureType.cpp\
	$(CODE_PATH)StructureValue.cpp\
	$(CODE_PATH)Token.cpp\
	$(CODE_PATH)Tokenizer.cpp\
	$(CODE_PATH)QueryStatement.cpp\
	$(CODE_PATH)UpdateStatement.cpp\
	$(CODE_PATH)Utils.cpp\
	$(DATA_PATH)BlockStructuredFile.cpp\
	$(DATA_PATH)BlockStructuredFileHeader.cpp\
	$(DATA_PATH)MetadataBlock.cpp\
	$(DATA_PATH)Record.cpp\
	$(TEST_PATH)Assertion.cpp\
	$(TEST_PATH)EqualsAssertion.cpp\
	$(TEST_PATH)EqualsIntAssertion.cpp\
	$(TEST_PATH)TrueAssertion.cpp\
	$(TEST_PATH)TestCase.cpp\
	$(TEST_PATH)TestSuiteResult.cpp	


GLOBAL_CPP_H:=	$(CODE_PATH)BufferedDataManager.h\
	$(DATA_PATH)Block.h\
	$(CODE_PATH)CreateStatement.h\
	$(CODE_PATH)DataFile.h\
	$(CODE_PATH)DataManager.h\
	$(CODE_PATH)DataType.h\
	$(CODE_PATH)DataValue.h\
	$(CODE_PATH)DeleteStatement.h\
	$(CODE_PATH)Demon.h\
	$(CODE_PATH)EndStatement.h\
	$(CODE_PATH)Field.h\
	$(CODE_PATH)FileManager.h\
	$(CODE_PATH)FileInfo.h\
	$(CODE_PATH)InsertionStatement.h\
	$(CODE_PATH)IntType.h\
	$(CODE_PATH)IntValue.h\
	$(CODE_PATH)IOException.h\
	$(CODE_PATH)ITokenizer.h\
	$(CODE_PATH)KillDaemonException.h\
	$(CODE_PATH)OutPutter.h\
	$(CODE_PATH)ParserException.h\
	$(CODE_PATH)QueryStatement.h\
	$(DATA_PATH)RecordsBlock.h\
	$(CODE_PATH)RemoveStatement.h\
	$(CODE_PATH)SecondaryIndex.h\
	$(CODE_PATH)Statement.h\
	$(CODE_PATH)StatementParser.h\
	$(CODE_PATH)StatementParserException.h\
	$(CODE_PATH)StatementResult.h\
	$(CODE_PATH)StatsStatement.h\
	$(CODE_PATH)StringType.h\
	$(CODE_PATH)StringValue.h\
	$(CODE_PATH)StructureType.h\
	$(CODE_PATH)StructureValue.h\
	$(CODE_PATH)Token.h\
	$(CODE_PATH)Tokenizer.h\
	$(CODE_PATH)UpdateStatement.h\
	$(CODE_PATH)Utils.h\
	$(DATA_PATH)BlockStructuredFile.h\
	$(DATA_PATH)BlockStructuredFileHeader.h\
	$(DATA_PATH)MetadataBlock.h\
	$(DATA_PATH)Record.h\
	$(TEST_PATH)Assertion.h\
	$(TEST_PATH)EqualsAssertion.h\
	$(TEST_PATH)EqualsIntAssertion.h\
	$(TEST_PATH)TrueAssertion.h\
	$(TEST_PATH)TestCase.h\
	$(TEST_PATH)TestSuiteResult.h

#Si se quiere arrancar usando un "main" propio, crear el archivo con la funcion main adentro y decomentar la linea que corresponda

MAIN_CLASS= $(CODE_PATH)main.cpp
MAIN_PABLO= $(CODE_PATH)main.cpp
MAIN_NAHUEL= $(CODE_PATH)TestSuite_BlockStructuredFile.cpp
#$(CODE_PATH)main_nahuel.cpp
MAIN_NICOLAS= $(CODE_PATH)main.cpp

#Lo que esta antes de ":" es una etiqueta. A la derecha de ":" van todos (.h y .cpp) los archivos que se van a usar.
#$(TARGET): $(MAIN_CLASS) $(CODE_PATH)StringType.cpp $(CODE_PATH)StringType.h $(CODE_PATH)DataType.cpp $(CODE_PATH)DataType.h $(CODE_PATH)IntType.h $(CODE_PATH)IntType.cpp $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
#	g++ -Wall $(MAIN_CLASS) $(CODE_PATH)StringType.cpp $(CODE_PATH)DataType.cpp $(CODE_PATH)IntType.cpp $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp

#El eclipse ejecuta el makefile usando "make all". Y "All" apunta a TARGET. Por lo tanto se ejecuta lo que dice en la etiqueta TARGET
all: $(MAIN_NICOLAS) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_NICOLAS) $(GLOBAL_CPP) -o $(TARGET)		
	
#Sirve para limpiar. Para ejecutar la limpieza hay que ejecutar "make clean"
clean:
	rm -f $(TARGET)
	
#all: $(MAIN_NAHUEL) $(GLOBAL_CPP_H)
#	g++ -Wall $(MAIN_CLASS) $(GLOBAL_CPP) -o $(TARGET)

pablo: $(MAIN_PABLO) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_PABLO) $(GLOBAL_CPP) -o $(TARGET)	


nahuel: $(MAIN_NAHUEL) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_NAHUEL) \
	$(GLOBAL_CPP) -o $(TARGET)

nicolas: $(MAIN_NICOLAS) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_NICOLAS) $(GLOBAL_CPP) -o $(TARGET)		