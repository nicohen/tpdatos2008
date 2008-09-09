#!/bin/sh

# escribir Makefile

BINNAME=mrt

echo 'CLASSPATHS=lib/htmlparser.jar:lib/servlet-api.jar:lib/junit-4.5.jar:lib/log4j-1.2.15.jar' > makefile
echo 'JFLAGS = -g -classpath $(CLASSPATHS)' >> makefile
echo 'JC = javac' >> makefile

#echo .SUFFIXES: .java .class >> makefile
#echo '.java.class:        $(JC) $(JFLAGS) $*.java' >> makefile


echo >> Makefile

echo "CLASSES = "$( find -name '*.java' ) >> makefile
echo  >> Makefile
echo "default: classes"  >> Makefile
echo 'classes:
	$(JC) $(JFLAGS) $(CLASSES)'  >> makefile
echo 'clean:
	   rm $(find -name '"'"'*.class'"'"')'  >> makefile

echo >> makefile

find -name '*.java' | sed -e 's/\.java//' | awk '{ print  $1 ".class: " $1 ".java\n\t\t$(JC) $(JFLAGS) $*.java" }' >> makefile

echo >> makefile
echo >> makefile


#aclocal
#autoconf
#automake -a
#autoheader



