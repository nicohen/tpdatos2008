#import "stdio.h"
#import "string.h"
#import "stdlib.h"
#import "SecondaryIndex.h"
#import "DataType.h"
#import "IntType.h"
#import "StringType.h"

int main(int argc, char **argv) {
	SecondaryIndex* vvSecondaryIndex=NULL;
	IntType* vvIntType=NULL;
	StringType* vvStringType=NULL;
	
	vvIntType=new IntType();
	vvStringType=new StringType();
	vvSecondaryIndex= new SecondaryIndex();
	printf("Hola desde el main de nahuel");	
	return 0;
}
