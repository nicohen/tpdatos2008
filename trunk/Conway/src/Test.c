#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
	printf("\"123p\" is numeric? %d\n",isNumericString("123p"));
	printf("\"123\" is numeric? %d\n",isNumericString("123"));
	printf("\"123,5\" is numeric? %d\n",isNumericString("123,5"));
	return 1;
}
