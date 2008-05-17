CC=g++
LDFLAGS= -Wall -g
EXECUTABLE=AlmacenX

CODE_PATH:= Codigo/
DATA_PATH:= $(CODE_PATH)Data/
BUFFER_PATH:= $(CODE_PATH)Buffer/
TEST_PATH:= $(CODE_PATH)TestingFramework/
HASH_PATH:= $(CODE_PATH)Hash/

MAIN_CLASS= $(CODE_PATH)main.cpp
MAIN_PABLO= $(CODE_PATH)main_pablo.cpp
MAIN_NAHUEL= $(CODE_PATH)TestSuite_BlockStructuredFile.cpp

SOURCES:=	$(CODE_PATH)BufferedDataManager.cpp\
	$(DATA_PATH)Block.cpp\
	$(DATA_PATH)KeysBlockFactory.cpp\
	$(DATA_PATH)RecordsBlockFactory.cpp\
	$(DATA_PATH)BlockFactory.cpp\
	$(DATA_PATH)MetadataBlockFactory.cpp\
	$(BUFFER_PATH)BufferKey.cpp\
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
	$(DATA_PATH)FileNotFoundException.cpp\
	$(DATA_PATH)FileDoesAlreadyExistsException.cpp\
	$(DATA_PATH)IdentityException.cpp\
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
	$(BUFFER_PATH)SystemBuffer.cpp\
	$(CODE_PATH)Token.cpp\
	$(CODE_PATH)Tokenizer.cpp\
	$(CODE_PATH)QueryStatement.cpp\
	$(CODE_PATH)UpdateStatement.cpp\
	$(CODE_PATH)Utils.cpp\
	$(DATA_PATH)BlockNotFoundException.cpp\
	$(DATA_PATH)BlockStructuredFile.cpp\
	$(DATA_PATH)BlockStructuredFileHeader.cpp\
	$(DATA_PATH)MetadataBlock.cpp\
	$(DATA_PATH)RawRecord.cpp\
	$(DATA_PATH)Record.cpp\
	$(TEST_PATH)Assertion.cpp\
	$(TEST_PATH)EqualsAssertion.cpp\
	$(TEST_PATH)EqualsIntAssertion.cpp\
	$(TEST_PATH)TrueAssertion.cpp\
	$(TEST_PATH)TestCase.cpp\
	$(TEST_PATH)TestSuiteResult.cpp\
	$(DATA_PATH)TypeMismatchException.cpp\
	$(BUFFER_PATH)IComparable.cpp\
	$(BUFFER_PATH)ComparableExample.cpp\
	$(DATA_PATH)BlockStructuredFileException.cpp\
	$(BUFFER_PATH)ReplacementSelector.cpp\
	$(BUFFER_PATH)IBuffereable.cpp\
	$(BUFFER_PATH)BlocksBuffer.cpp\
	$(BUFFER_PATH)DataFilesBufferKey.cpp\
	$(BUFFER_PATH)DataFilesBuffer.cpp\
	$(DATA_PATH)ContentOverflowBlockException.cpp\
	$(DATA_PATH)RecordSizeOverflowException.cpp\
	$(DATA_PATH)KeysBlock.cpp\
	$(HASH_PATH)HashTable.cpp\
	$(DATA_PATH)HashIndex.cpp
	
OBJECTS=$(SOURCES:.cpp=.o)

	
#Si se quiere arrancar usando un "main" propio, crear el archivo con la funcion main adentro y decomentar la linea que corresponda

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(MAIN_CLASS) $(OBJECTS) -o $(EXECUTABLE)

nahuel:	$(OBJECTS) 
	$(CC) $(LDFLAGS) $(MAIN_NAHUEL) $(OBJECTS) -o $(EXECUTABLE)

pablo: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(MAIN_PABLO) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(LDFLAGS) $< -c -o $@

clean:
	rm -f $(EXECUTABLE)

clean-all:
	rm -f $(EXECUTABLE)
	rm -f $(CODE_PATH)*.o
	rm -f $(DATA_PATH)*.o
	rm -f $(BUFFER_PATH)*.o
	rm -f $(TEST_PATH)*.o