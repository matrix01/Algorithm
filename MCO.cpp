#include<iostream>
#include<stdio.h>
#define MAX 15 /* number of matrix */
#define INF 4294967295 /* a maximum number of multiplication */
using namespace std;
int num;
void print(long s[][MAX],int i,int j){
	if(i==j)
		printf("A%d",num++);
	else{
		printf("(");
		print(s,i,s[i][j]);
		printf(" x ");
		print(s,s[i][j]+1,j);
		printf(")");
	}
}
void matrix_chan_order(int *p,int n){
	long m[MAX][MAX] = {0};
	long s[MAX][MAX] = {0};
	int q;
	int l,j,i,k;
	for(l = 2; l <= n ;l++){
		for(i = 1 ; i <= n - l +1 ; i++){
			j = i + l -1;
			m[i][j] = INF; 
			for(k=i ; k < j ; k++) {
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%ld\n", m[1][n-1]);
	num =1;
	print(s,1,n);
}
int main(){
	int n;
	int p[MAX]={0};
	int i;
	while(scanf("%d",&n)==1){
		for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	matrix_chan_order(p,n);
	printf("\n");
	}
	return 0;
}