TARGET = AlmacenX

OBJ =

CODE_PATH= Codigo/

#MAIN_CLASS= $(CODE_PATH)main_nahuel.cpp
MAIN_CLASS= $(CODE_PATH)main.cpp

$(TARGET): $(CODE_PATH)SecondaryIndex.h $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp    $(CODE_PATH)main.cpp
	g++ -Wall $(CODE_PATH)Utils.cpp $(CODE_PATH)SecondaryIndex.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp $(MAIN_CLASS) -o $(TARGET)

all: $(TARGET)
clean:
	rm -f $(TARGET)
