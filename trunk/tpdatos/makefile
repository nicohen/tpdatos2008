CLASSPATHS=lib/htmlparser.jar:lib/servlet-api.jar:lib/junit-4.5.jar:lib/log4j-1.2.15.jar
JFLAGS = -g -classpath $(CLASSPATHS)
JC = javac
RM = rm

#.SUFFIXES: .java .class
#.java.class:
#        $(JC) $(JFLAGS) $*.java

CLASSES = ./src/files/IApilable.java ./src/files/AbstractFile.java ./src/files/SecuencialFile.java ./src/files/File.java ./src/files/StackFile.java ./src/persistors/Persistor.java ./src/persistors/StringPersistor.java ./src/persistors/AbstractPersistor.java ./src/persistors/IntegerPersistor.java ./src/persistors/BytePersistor.java ./src/exceptions/BusinessException.java ./src/exceptions/DataAccessException.java ./src/api/ObjectFactory.java ./src/ControllerServlet.java ./src/test.java ./src/SecuentialFileTest.java ./src/FileTest.java ./src/StackFileTest.java

default: classes

classes: 
	$(JC) $(JFLAGS) $(CLASSES)

clean:
	rm $(find -name *.class)
