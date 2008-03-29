#Esto es un comentario

#TARGET es una variable que se va a usar mas abajo. Indica el nombre del archivo que se va a ejecutar 
TARGET = AlmacenX

#Una variable que no se usa
#OBJ =

#Es la ruta para llegar a los archivos que estan en el codigo
CODE_PATH= Codigo/

#Define el archivo que contiene el main.
MAIN_CLASS= $(CODE_PATH)main.cpp

#Si se quiere arrancar usando un "main" propio, crear el archivo con la funcion main adentro y decomentar la linea que corresponda
MAIN_NICOLAS= $(CODE_PATH)main_nico.cpp
MAIN_PABLO= $(CODE_PATH)main_pablo.cpp
MAIN_NAHUEL= $(CODE_PATH)main_nahuel.cpp

#Lo que esta antes de ":" es una etiqueta. A la derecha de ":" van todos (.h y .cpp) los archivos que se van a usar.
$(TARGET): $(MAIN_CLASS) $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
	g++ -Wall $(MAIN_CLASS) $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp  -o $(TARGET)

#El eclipse ejecuta el makefile usando "make all". Y "All" apunta a TARGET. Por lo tanto se ejecuta lo que dice en la etiqueta TARGET
all: $(TARGET)

#Sirve para limpiar. Para ejecutar la limpieza hay que ejecutar "make clean"
clean:
	rm -f $(TARGET)

pablo: $(MAIN_PABLO) $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
	g++ -Wall $(MAIN_PABLO) $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp  -o $(TARGET)

nahuel: $(MAIN_NAHUEL) $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
	g++ -Wall $(MAIN_NAHUEL) $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp  -o $(TARGET)	

nicolas: $(MAIN_NICOLAS) $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp
#Aca se le da la instrucción al compilador para que compile todos los cpp
	g++ -Wall $(MAIN_NICOLAS) $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp  -o $(TARGET)	