#!/bin/sh

# escribir Makefile

BINNAME=mrt

echo 'CLASSPATHS=src:WEB-INF/lib/htmlparser.jar:WEB-INF/lib/servlet-api.jar:WEB-INF/lib/junit-4.5.jar:WEB-INF/lib/log4j-1.2.15.jar' > makefile

echo >> makefile
echo 'JFLAGS = -g:none -classpath $(CLASSPATHS) -d WEB-INF/classes/ -source 1.6 -target 1.6' >> makefile
echo 'JC = javac' >> makefile

#echo .SUFFIXES: .java .class >> makefile
#echo '.java.class:        $(JC) $(JFLAGS) $*.java' >> makefile


echo >> makefile
echo >> makefile

CLASSES=$(find -name '*.java'  | sed -e 's/\.java$/\.class/' | sed -e 's/\.\/src/WEB-INF\/classes/' )
CLASSESSRC=$(find -name '*.java'  | sed -e 's/src\///' -e 's/\.java$/\.class/')
CLASSESBIN=$(find -name '*.java'  | sed -e 's/\.\/src\///' -e 's/\.java$/\.class/')


echo "CLASSES = "$( find -name '*.java' ) >> makefile
echo  >> makefile
echo "default: classes war jar"  >> makefile
echo "classes: "$CLASSES >> makefile
echo 'clean:
	   rm '$CLASSES''  >> makefile
echo 'war:
	cp src/log4j.xml WEB-INF/classes/
	test -d documents || mkdir documents
	jar cfm bombita.war manifesto.txt words/ html/ documents/ WEB-INF/'>> makefile

echo 'jar:
	cp src/log4j.xml WEB-INF/classes/
	test -d documents || mkdir documents
	cd WEB-INF/classes && jar cfm ../../bombita.jar ../../manifesto-jar.txt ../../words/ ../../html/ ../../documents/  .'>> makefile

echo 'dist:
	mv WEB-INF/classes WEB-INF/classes.tmp
	mkdir WEB-INF/classes
	tar -c '$( find -name "*.java" )' leemeporfavor.txt manifesto.txt manifesto-jar.txt html/* src/log4j.xml words/stemming.txt words/stopwords.txt makefile WEB-INF/classes WEB-INF/web.xml '$(find WEB-INF/lib/ -name '*.jar')' > bombita-src.tar 
	rmdir WEB-INF/classes
	mv WEB-INF/classes.tmp WEB-INF/classes
	gzip --force bombita-src.tar 
	@echo "*************************************************"
	@echo "* 	bombita-src.tar.gz generated	       *"
	@echo "*************************************************" ' >> makefile 

echo >> makefile

cd src

#find -name '*.java'| sed 's/\.\///' | sed -e 's/\.java//' | awk '{ print  "bin/" $1 ".class: src/" $1 ".java\n\t\t$(JC) $(JFLAGS) src/" $1 ".java && mv src/" $1 ".class bin/" $1 ".class " }' >> ../makefile
find -name '*.java'| sed 's/\.\///' | sed -e 's/\.java//' | awk '{ print  "WEB-INF/classes/" $1 ".class: src/" $1 ".java\n\t\t$(JC) $(JFLAGS) src/" $1 ".java" }' >> ../makefile

cd ..


echo >> makefile
echo >> makefile

