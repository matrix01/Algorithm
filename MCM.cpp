#include<iostream>
#include<stdio.h>
#define INT_MAX 999999
using namespace std;
int m[100][100];
int s[100][100];

int Matrix_Chain_order(int p[], int n){
	int i, j, k, L, q;
	for (i = 1; i < n; i++){
		m[i][i] = 0;
		s[i][i]=0;
	}
 
    // L is chain length.  
	for (L=2; L<n; L++){
		for (i=1; i<=n-L+1; i++){
            j = i+L-1;
            m[i][j] = INT_MAX;
			for (k=i; k<=j-1; k++){
                // q = cost/scalar multiplications
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				//printf("%d = m[%d][%d]+m[%d][%d]+p[%d]*p[%d]*p[%d]\n", q, i, k,k+1,j,i-1,k,j);
				//printf("%d = %d+%d+%d*%d*%d\n", q, m[i][k],m[k+1][j],p[i-1],p[k],p[j]);
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j]=k;
					//cout<<"Minimun:  "<<m[i][j]<<endl;
				}
			}
			cout<<endl<<endl;
		}
	}
	//print(s, 1, n);
	return m[1][n-1];
	
}
void show(){
	cout<<"M-Table: "<<endl;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			printf("%6d", m[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"S-Table: "<<endl;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			printf("%6d", s[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	
	int arr[] = {12, 9, 15, 25, 3};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Minimum number of multiplications is %d \n", Matrix_Chain_order(arr, size));
	show();
	return 0;
}