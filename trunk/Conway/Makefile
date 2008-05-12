SRCFOLDER =	src/
CXXFLAGS =	-ansi -g -Wall
OBJECTS =	$(SRCFOLDER)Utils.o\
			$(SRCFOLDER)Board.o
SOURCES =	$(SRCFOLDER)Utils.c\
			$(SRCFOLDER)Board.c
TARGET = 	Conway.exe

all:	$(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(SRCFOLDER)Conway.c

test: $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(SRCFOLDER)Test.c

clean:
	rm -f $(OBJECTS) $(TARGET)

$(SRCFOLDER)Utils.o:
	$(CXX) $(CXXFLAGS) $(SRCFOLDER)Utils.c -c -o $(SRCFOLDER)Utils.o 

$(SRCFOLDER)Board.o:
	$(CXX) $(CXXFLAGS) $(SRCFOLDER)Board.c -c -o $(SRCFOLDER)Board.o