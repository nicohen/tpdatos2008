#!/bin/sh

# escribir Makefile

BINNAME=mrt

echo 'CLASSPATHS=src:lib/htmlparser.jar:lib/servlet-api.jar:lib/junit-4.5.jar:lib/log4j-1.2.15.jar' > makefile

echo >> makefile

echo 'JFLAGS = -g -classpath $(CLASSPATHS)' >> makefile
echo 'JC = javac' >> makefile

#echo .SUFFIXES: .java .class >> makefile
#echo '.java.class:        $(JC) $(JFLAGS) $*.java' >> makefile


echo >> makefile
echo >> makefile

echo "CLASSES = "$( find -name '*.java' ) >> makefile
echo  >> makefile
echo "default: classes"  >> makefile
echo 'classes:   $(CLASSES:.java=.class)'  >> makefile
echo 'clean:
	   rm $(CLASSES:.java=.class)'  >> makefile

echo >> makefile

find -name '*.java' | sed -e 's/\.java//' | awk '{ print  $1 ".class: " $1 ".java\n\t\t$(JC) $(JFLAGS) " $1 ".java" }' >> makefile

echo >> makefile
echo >> makefile
