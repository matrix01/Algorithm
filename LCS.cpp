#include<iostream>
#include<string>
using namespace std;
string X,Y;
int c[101][101];
int m,n,ctr;
 
void LCS(){
     m = X.length(),n=Y.length();
 
     int i,j;
     for (i=0;i<=m;i++)
         for (j=0;j<=n;j++)
             c[i][j]=0;
 
     for (i=1;i<=m;i++)
         for (j=1;j<=n;j++){
             if (X[i-1]==Y[j-1])
                c[i][j]=c[i-1][j-1]+1;
             else
                 c[i][j]=max(c[i][j-1],c[i-1][j]);
         }
		 cout<<"LCS Length: "<<c[i-1][j-1]<<endl;
}
 
void printLCS(int i,int j){
    if (i==0 || j==0)
       return;
    if (X[i-1]==Y[j-1]){
       printLCS(i-1,j-1);
       cout<<X[i-1];
    }
    else if (c[i][j]==c[i-1][j])
         printLCS(i-1,j);
    else
        printLCS(i,j-1);
}
void show(){
	for(int i=0; i<11; i++){
		for(int j=0; j<10; j++){
			cout<<c[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int main(){
    while(cin>>X>>Y){
        LCS();
        printLCS(m,n);
        cout<<endl ;
    show();
	}
	return 0;
}