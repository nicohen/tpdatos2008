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

CLASSES=$(find -name '*.java'  | sed -e 's/\.\/src/\.\/bin/' -e 's/\.java$/\.class/')
CLASSESBIN=$(find -name '*.java'  | sed -e 's/\.\/src\///' -e 's/\.java$/\.class/')


echo "CLASSES = "$( find -name '*.java' ) >> makefile
echo  >> makefile
echo "default: classes"  >> makefile
echo "classes: "$CLASSES >> makefile
echo 'clean:
	   rm $(CLASSES:.java=.class)'  >> makefile
echo 'jar:
	jar cvf bombita.jar -C bin/ .' >> makefile

echo >> makefile

cd src

#find -name '*.java'| sed 's/\.\///' | sed -e 's/\.java//' | awk '{ print  "bin/" $1 ".class: src/" $1 ".java\n\t\t$(JC) $(JFLAGS) src/" $1 ".java && mv src/" $1 ".class bin/" $1 ".class " }' >> ../makefile
find -name '*.java'| sed 's/\.\///' | sed -e 's/\.java//' | awk '{ print  "bin/" $1 ".class: src/" $1 ".java\n\t\t$(JC) $(JFLAGS) src/" $1 ".java" }' >> ../makefile

cd ..


echo >> makefile
echo >> makefile

