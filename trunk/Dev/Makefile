#Esto es un comentario

#TARGET es una variable que se va a usar mas abajo. Indica el nombre del archivo que se va a ejecutar 
TARGET = AlmacenX

#Una variable que no se usa
#OBJ =

#Es la ruta para llegar a los archivos que estan en el codigo
CODE_PATH= Codigo/
 
#Archivos que estan en producción
GLOBAL_CPP_H=  $(CODE_PATH)StatementResult.h  $(CODE_PATH)Registry.h  $(CODE_PATH)BufferedDataManager.h $(CODE_PATH)DataManager.h  $(CODE_PATH)StructureType.h $(CODE_PATH)StatementParser.h    $(CODE_PATH)Statement.h   $(CODE_PATH)OutPutter.h   $(CODE_PATH)Field.h   $(CODE_PATH)CreateStatement.h   $(CODE_PATH)StringType.h   $(CODE_PATH)DataType.h   $(CODE_PATH)IntType.h   $(CODE_PATH)Utils.h   $(CODE_PATH)SecondaryIndex.h   $(CODE_PATH)IOException.h   $(CODE_PATH)FileManager.h   $(CODE_PATH)FileInfo.h   $(CODE_PATH)Demon.h   $(CODE_PATH)Token.h   $(CODE_PATH)Tokenizer.h
GLOBAL_CPP= $(CODE_PATH)StatementResult.cpp  $(CODE_PATH)Registry.cpp $(CODE_PATH)BufferedDataManager.cpp  $(CODE_PATH)DataManager.cpp $(CODE_PATH)StructureType.cpp $(CODE_PATH)StatementParser.cpp  $(CODE_PATH)Statement.cpp $(CODE_PATH)OutPutter.cpp $(CODE_PATH)Field.cpp $(CODE_PATH)CreateStatement.cpp $(CODE_PATH)StringType.cpp $(CODE_PATH)DataType.cpp $(CODE_PATH)IntType.cpp $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp $(CODE_PATH)Token.cpp $(CODE_PATH)Tokenizer.cpp

#Si se quiere arrancar usando un "main" propio, crear el archivo con la funcion main adentro y decomentar la linea que corresponda
MAIN_CLASS= $(CODE_PATH)main.cpp
MAIN_PABLO= $(CODE_PATH)main.cpp
MAIN_NAHUEL= $(CODE_PATH)main_nahuel.cpp
MAIN_NICOLAS= $(CODE_PATH)main_nico.cpp

#Lo que esta antes de ":" es una etiqueta. A la derecha de ":" van todos (.h y .cpp) los archivos que se van a usar.
#$(TARGET): $(MAIN_CLASS) $(CODE_PATH)StringType.cpp $(CODE_PATH)StringType.h $(CODE_PATH)DataType.cpp $(CODE_PATH)DataType.h $(CODE_PATH)IntType.h $(CODE_PATH)IntType.cpp $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
#	g++ -Wall $(MAIN_CLASS) $(CODE_PATH)StringType.cpp $(CODE_PATH)DataType.cpp $(CODE_PATH)IntType.cpp $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp

#El eclipse ejecuta el makefile usando "make all". Y "All" apunta a TARGET. Por lo tanto se ejecuta lo que dice en la etiqueta TARGET
all: $(TARGET2)

#Sirve para limpiar. Para ejecutar la limpieza hay que ejecutar "make clean"
clean:
	rm -f $(TARGET)
	
#all: $(MAIN_NAHUEL) $(GLOBAL_CPP_H)
#	g++ -Wall $(MAIN_CLASS) $(GLOBAL_CPP) -o $(TARGET)

pablo: $(MAIN_PABLO) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_PABLO) $(GLOBAL_CPP) -o $(TARGET)	


nahuel: $(MAIN_NAHUEL) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_NAHUEL) $(GLOBAL_CPP) -o $(TARGET)

nicolas: $(MAIN_NICOLAS) $(GLOBAL_CPP_H)
	g++ -Wall $(MAIN_NICOLAS) $(GLOBAL_CPP) -o $(TARGET)		