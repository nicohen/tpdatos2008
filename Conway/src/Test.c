#include "Utils.h"
#include "Assertions.h"
#include <stdio.h>

void numericTest(){
	ASSERT_FALSE(isNumericString("123p"));
	ASSERT_TRUE(isNumericString("123"));
	ASSERT_FALSE(isNumericString("123.5"));
	ASSERT_TRUE(isNumericString("015"));
}

int main(int argc, char **argv) {
	numericTest();
	printf("----Fin de Tests---");
	return 1;
}

