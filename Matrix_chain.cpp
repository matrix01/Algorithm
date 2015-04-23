#include<iostream>
#include<stdio.h>
#define row 2
#define col 2
#define row1 2
#define col1 2
#define row3 2
#define col3 2
#define fin (freopen("M_C_in.txt", "r", stdin))
using namespace std;
int a[10][10], b[10][10], c[10][10];
void M_C(){
	if(row!=col) {
		cout<<"Icorrect Dimensions."<<endl;
		return;
	}
	for(int i=0; i<row3; i++){

		for(int j=0; j<col3; j++){
			c[i][j]=0;
			for(int k=0; k<col1; k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
}
void show(){
	for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				cout<<c[i][j]<<" ";
			}
			cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				cin>>a[i][j];
		for(int i=0; i<row1; i++)
			for(int j=0; j<col1; j++)
				cin>>b[i][j];
		M_C();
		show();
	}
	fclose(stdin);
	return 0;
}