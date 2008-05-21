#include "Vecinos.h"

unsigned int vecinos(unsigned char *a, unsigned int i, unsigned int j, unsigned int M, unsigned int N){
	int x,y;
	unsigned int activos=0;
	x=((i-1)<0)?M-1:(i-1);
	y=((j-1)<0)?N-1:(j-1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	y=j;
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	y=((j+1)==N)?0:(j+1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	x=i;
	y=((j-1)<0)?N-1:(j-1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	y=((j+1)==N)?0:(j+1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	x=((i+1)==M)?0:(i+1);
	y=((j-1)<0)?N-1:(j-1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	y=j;
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	y=((j+1)==N)?0:(j+1);
	if(a[(x*N)+y]=='1'){
		activos++;
	}
	return activos;
}
