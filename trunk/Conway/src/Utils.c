#include <string.h>

int isNumericString(char* string){
	int length;
	int i=0;
	length= strlen(string);
	while(i<length){
		if ((string[i]<'0')||(string[i]>'9')){
			return 0;
		}
		i++;
	}
	return 1;
}
