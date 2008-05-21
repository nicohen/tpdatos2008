SRCFOLDER =	src/
CXXFLAGS =	-ansi -g -Wall
OBJECTS =	$(SRCFOLDER)Utils.o\
			$(SRCFOLDER)Board.o\
			$(SRCFOLDER)Files.o
SOURCES =	$(SRCFOLDER)Utils.c\
			$(SRCFOLDER)Board.c\
			$(SRCFOLDER)Files.c
TARGET = 	Conway.exe
VECINOS_C = $(SRCFOLDER)Vecinos.c
VECINOS_MIPS = $(SRCFOLDER)Vecinos.S

all:	$(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(VECINOS_C) $(SRCFOLDER)Conway.c

mips:	$(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(VECINOS_MIPS) $(SRCFOLDER)Conway.c

test: $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(VECINOS_C) $(SRCFOLDER)Test.c

clean:
	rm -f $(OBJECTS) $(TARGET)

$(SRCFOLDER)Utils.o: $(SRCFOLDER)Utils.c $(SRCFOLDER)Utils.h
	$(CXX) $(CXXFLAGS) $(SRCFOLDER)Utils.c -c -o $(SRCFOLDER)Utils.o 

$(SRCFOLDER)Board.o: $(SRCFOLDER)Board.c $(SRCFOLDER)Board.h
	$(CXX) $(CXXFLAGS) $(SRCFOLDER)Board.c -c -o $(SRCFOLDER)Board.o

$(SRCFOLDER)Files.o: $(SRCFOLDER)Files.c $(SRCFOLDER)Files.h $(SRCFOLDER)Board.o
	$(CXX) $(CXXFLAGS) $(SRCFOLDER)Files.c -c -o $(SRCFOLDER)Files.o