TARGET = AlmacenX

OBJ =

CODE_PATH= Codigo/

$(TARGET):$(CODE_PATH)Utils.h    $(CODE_PATH)Utils.cpp    $(CODE_PATH)IOException.h    $(CODE_PATH)IOException.cpp    $(CODE_PATH)FileManager.h    $(CODE_PATH)FileManager.cpp    $(CODE_PATH)FileInfo.h    $(CODE_PATH)FileInfo.cpp    $(CODE_PATH)Demon.h    $(CODE_PATH)Demon.cpp    $(CODE_PATH)main.cpp
	g++ -Wall $(CODE_PATH)Utils.cpp $(CODE_PATH)IOException.cpp $(CODE_PATH)FileManager.cpp $(CODE_PATH)FileInfo.cpp $(CODE_PATH)Demon.cpp $(CODE_PATH)main.cpp -o $(TARGET)

all: $(TARGET)
clean:
	rm -f $(TARGET)
    
#OBJS =		AlmacenX.o

#LIBS =

#TARGET =	AlmacenX

#$(TARGET):	$(OBJS)
#	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

#all:	$(TARGET)

#clean:
#	rm -f $(OBJS) $(TARGET)
