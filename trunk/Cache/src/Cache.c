#define N 192

int main(void) {
	double a[N][N],b[N][N],c[N][N];
	int i,j,k;
	
	for (i=0;i<N;i++) 
		for (j=0;j<N;i++)
			for (k=0;k<N;i++)
				c[i][j] += a[i][k]*b[k][j];
	
	return 0;
}
