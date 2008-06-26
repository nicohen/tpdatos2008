#define N 192
#define B 128
#define P 8
#define D 16 
#define PREFETCH(m,x,y) prefetch = (int) m[x][y];

int mainOriginal(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	register int prefetch;
	
	for (i=0;i<N;i++){ 
		for (j=0;j<N;j++){
			for (k=0;k<D;k+=8) {
				PREFETCH(a,i,k);
			}
			for (k=0;k<N-D;k+=8) {
				PREFETCH(a,i,k+D);
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] += a[i][k+1]*b[k+1][j];
				c[i][j] += a[i][k+2]*b[k+2][j];
				c[i][j] += a[i][k+3]*b[k+3][j];
				c[i][j] += a[i][k+4]*b[k+4][j];
				c[i][j] += a[i][k+5]*b[k+5][j];
				c[i][j] += a[i][k+6]*b[k+6][j];
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
			for (k=N-D;k<N;k+=8) {
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] += a[i][k+1]*b[k+1][j];
				c[i][j] += a[i][k+2]*b[k+2][j];
				c[i][j] += a[i][k+3]*b[k+3][j];
				c[i][j] += a[i][k+4]*b[k+4][j];
				c[i][j] += a[i][k+5]*b[k+5][j];
				c[i][j] += a[i][k+6]*b[k+6][j];
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
		}
	}
	
	return 0;
}

int mainPadding(void) {
	double a[N][N],pad1[P],b[N][N],pad2[P],c[N][N];
	int i,j,k;
	
	for (i=0;i<N;i++) 
		for (j=0;j<N;j++)
			for (k=0;k<N;k++)
				c[i][j] += a[i][k]*b[k][j];
	
	return 0;
}


int mainBloquing(void) {
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

int main5 (void) {
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

int mainDoblePrefetch(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	register int prefetch;
	
	for (i=0;i<N;i++){ 
		for (j=0;j<N;j++){
			for (k=0;k<D;k+=8) {
				PREFETCH(a,i,k);
				PREFETCH(b,i,k);
				PREFETCH(b,i,k+1);
				PREFETCH(b,i,k+2);
				PREFETCH(b,i,k+3);
				PREFETCH(b,i,k+4);
				PREFETCH(b,i,k+5);
				PREFETCH(b,i,k+6);
				PREFETCH(b,i,k+7);
			}
			for (k=0;k<N-D;k+=8) {
				PREFETCH(a,i,k+D);
				PREFETCH(b,i,k+D);
				c[i][j] += a[i][k]*b[k][j];
				PREFETCH(b,i,k+D+1);
				c[i][j] += a[i][k+1]*b[k+1][j];
				PREFETCH(b,i,k+D+2);
				c[i][j] += a[i][k+2]*b[k+2][j];
				PREFETCH(b,i,k+D+3);
				c[i][j] += a[i][k+3]*b[k+3][j];
				PREFETCH(b,i,k+D+4);
				c[i][j] += a[i][k+4]*b[k+4][j];
				PREFETCH(b,i,k+D+5);
				c[i][j] += a[i][k+5]*b[k+5][j];
				PREFETCH(b,i,k+D+6);
				c[i][j] += a[i][k+6]*b[k+6][j];
				PREFETCH(b,i,k+D+7);
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
			for (k=N-D;k<N;k+=8) {
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] += a[i][k+1]*b[k+1][j];
				c[i][j] += a[i][k+2]*b[k+2][j];
				c[i][j] += a[i][k+3]*b[k+3][j];
				c[i][j] += a[i][k+4]*b[k+4][j];
				c[i][j] += a[i][k+5]*b[k+5][j];
				c[i][j] += a[i][k+6]*b[k+6][j];
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
		}
	}
	
	return 0;
}

int mainTriplePrefetch(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	register int prefetch;
	
	for (i=0;i<N;i++){ 
		for (j=0;j<N;j++){
			PREFETCH(c,i,j);
			for (k=0;k<D;k+=8) {
				PREFETCH(a,i,k);
				PREFETCH(b,i,k);
				PREFETCH(b,i,k+1);
				PREFETCH(b,i,k+2);
				PREFETCH(b,i,k+3);
				PREFETCH(b,i,k+4);
				PREFETCH(b,i,k+5);
				PREFETCH(b,i,k+6);
				PREFETCH(b,i,k+7);
			}
			for (k=0;k<N-D;k+=8) {
				PREFETCH(a,i,k+D);
				PREFETCH(b,i,k+D);
				c[i][j] += a[i][k]*b[k][j];
				PREFETCH(b,i,k+D+1);
				c[i][j] += a[i][k+1]*b[k+1][j];
				PREFETCH(b,i,k+D+2);
				c[i][j] += a[i][k+2]*b[k+2][j];
				PREFETCH(b,i,k+D+3);
				c[i][j] += a[i][k+3]*b[k+3][j];
				PREFETCH(b,i,k+D+4);
				c[i][j] += a[i][k+4]*b[k+4][j];
				PREFETCH(b,i,k+D+5);
				c[i][j] += a[i][k+5]*b[k+5][j];
				PREFETCH(b,i,k+D+6);
				c[i][j] += a[i][k+6]*b[k+6][j];
				PREFETCH(b,i,k+D+7);
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
			for (k=N-D;k<N;k+=8) {
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] += a[i][k+1]*b[k+1][j];
				c[i][j] += a[i][k+2]*b[k+2][j];
				c[i][j] += a[i][k+3]*b[k+3][j];
				c[i][j] += a[i][k+4]*b[k+4][j];
				c[i][j] += a[i][k+5]*b[k+5][j];
				c[i][j] += a[i][k+6]*b[k+6][j];
				c[i][j] += a[i][k+7]*b[k+7][j];
			}
		}
	}
	
	return 0;
}

int main(void){
	return mainOriginal();
	//return mainPadding();
	//return mainBloquing();
	//return main5();
}
