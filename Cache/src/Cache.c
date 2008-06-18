#define N 192
#define B 8

int main(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	
	for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			for (k=0;k<N;k++)
				c[i][j] += a[i][k]*b[k][j];
	
	return 0;
}

int main2(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	double aux;
	
	for (i=0;i<N;i++) 
		for (j=0;j<N;j++){
			aux=0;
			for (k=0;k<N;k++)
				aux+=a[i][k]*b[k][j];
			c[i][j]=aux ;
		}
	
	return 0;
}

int main3(void) {
	double a[N][N],pad1[N][1],b[N][N],pad2[N][1],c[N][N];
	int i,j,k;
	
	for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			for (k=0;k<N;k++)
				c[i][j] += a[i][k]*b[k][j];
	
	return 0;
}


int main4(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	int jj,kk;
	
	for (jj=0;jj<N;jj+=B) 
	for (kk=0;kk<N;kk+=B)
	for (i=0;i<N;i++) 
		for (j=jj;j<jj+B;j++)
			for (k=kk;k<kk+B;k++)
				c[i][j] += a[i][k]*b[k][j];
	
	return 0;
}