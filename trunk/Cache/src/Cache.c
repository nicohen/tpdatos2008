#define N 192
#define B 8

int main1(void) {
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
	double a[N][N],pad1[8][1],b[N][N],pad2[8][1],c[N][N];
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

int main (void) {
	volatile double  a[N][N],b[N][N],c[N][N];
	register int i,j,k,jj,kk;
	register double temp;
	
	for (jj=0;jj<N;jj+=B)
		for (kk=0;kk<N;kk+=B) 
			for (i=0; i<N;i++)
				for (j=jj;j<jj+B;j++){
			
				    temp = 0.0;
				    for (k=kk;k<kk+B;k++) {
					temp+=a[i][k]*b[k][j];
				    }
				    c[i][j] = temp;
				}
	return 0;
}
