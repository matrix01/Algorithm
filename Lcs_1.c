#include<stdio.h>
#include<string.h>
#define max(a, b) ((a>b)?a:b)
#define MAX 100
char x[MAX], y[MAX];
int i, j, m, n, c[MAX][MAX], b[MAX][MAX];

int lcsRec(int i, int j) {
  if (i==0 || j==0) return 0;
  else if (x[i] == y[j])
    return lcsRec(i-1,j-1) + 1;
  else
    return max(lcsRec(i-1,j),lcsRec(i,j-1));
}

int main(){
	while(1){
		gets(x);
		gets(y);
		printf("LCS length ->%d\n", lcsRec(0, 0)); //count length
		printf("\n");
	}
return 0;
}

