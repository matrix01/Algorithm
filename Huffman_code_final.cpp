#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stdlib.h>
using namespace std;
const int max=10;
int fre[128]; string s;
string newstr;
class node{
public:
	int freq;
	string ch;
	node* right;
	node* left;
};
node* make_node(string a, int x){
	node* nptr= new node;
	nptr->freq = x;
	nptr->ch=a;
	//strcpy( nptr->ch , a);
	nptr->right = nptr->left = NULL;
	return nptr;
}
void sort(node* a[], int n){
	node* tptr;
	for (int i = 0; i < n-1 ; i++)
		for (int j = i; j < n; j++)
			if (a[i]->freq > a[j]->freq){
				tptr = a[i];
				a[i] = a[j];
				a[j] = tptr;
			}
			else if(a[i]->freq == a[j]->freq){
				if(a[i]->ch>a[j]->ch){
					tptr=a[i];
					a[i]=a[j];
					a[j]=tptr;
				}
			}
			/*for(int i=0; i<n; i++)
				cout<<a[i]->freq<<" "<<a[i]->ch<<endl;
			cout<<endl;*/
}
void shift_right(node* a[], int n){
	for (int i = 1; i < n - 1; i++)
		a[i] = a[i + 1];
}
void encode(node* tptr, int c[], int n){
	if ((tptr->left == NULL) && (tptr->right == NULL)){
		cout<<"code:   "<< tptr->ch<<" :   ";
		for (int i = 0; i < n; i++){
			cout<< c[i];
		}
		cout<<endl;
	}
	else{
		c[n] = 1;
		n++;
		encode(tptr->left, c, n);
		c[n - 1] = 0;
		encode(tptr->right, c, n);
	}
}
void del(node * root){
	if(root!=NULL){
		del(root->left);
		del(root->right);
		delete root;
	}
}
int main(){
	node* nptr;
	node* head;
	node* a[1000];
	int n=0,b,c[1000]={0};
	string str;
	cout<<"Enter the string to Encode: "<<endl;
	getline(cin, s);
	for(int i=0; i<s.length(); i++)
		fre[s[i]]++;
	for(int i=0; i<128; i++)
		if(fre[i]!=0){
			newstr=(char) i;
			//newstr[1]=0;
			//newstr[1]=NULL;
			//cout<<newstr<<endl;
			a[n++] = make_node(newstr, fre[i]);
		}
		//cout<<n<<endl;
	while (n > 1){
		sort(a, n);
		b = a[0]->freq + a[1]->freq;
		str=a[0]->ch+a[1]->ch;
		//cout<<str<<endl;
		//strcpy(str,a[0]->ch);
		//strcat(str,a[1]->ch);
		nptr = make_node(str, b);
		if(a[0]->ch>a[1]->ch){
			nptr->right = a[1];
			nptr->left = a[0];
		}
		else{
			nptr->right = a[0];
			nptr->left = a[1];
		}
		a[0] = nptr;
		shift_right(a, n);
		n--;
	}
	encode(a[0], c, 0);
	return 0;
}