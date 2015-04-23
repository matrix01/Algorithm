/*******************************
*	Program Name: Marge Sort
*	Written By	: Milan
*	Date		: 23.05.2013
********************************/
#include<iostream>
#define MAX 10000
using namespace std;
int a[MAX];
class margesort{
public:
	void marge(int , int , int );
	void marge_sort(int , int );
	void show(int);
};
void margesort::marge(int l, int m, int h){
	int temp1[MAX], temp2[MAX], n1, n2;
	n1=(m-l)+1;	//size of 1st half
	n2=h-m;	//size of 2nd half
	for(int i=0; i<n1; i++) temp1[i]=a[l+i];	//saving the 1st half into a temp array
	for(int i=0; i<n2; i++) temp2[i]=a[m+i+1];	//saving the 2nd half into a temp array
	temp1[n1]=99999;
	temp2[n2]=99999;
	int j=0, k=0;
	for(int i=l; i<=h; i++) { //Marging the array low to high
		if(temp1[j]<=temp2[k]){ //sorting the elements comparing 1st and 2nd half array
			a[i]=temp1[j++];
		}
		else
			a[i]=temp2[k++];
	}
}
void margesort::marge_sort(int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;	//dividing array in 2 part
		marge_sort(low, mid);	//sorting 1st half
		marge_sort(mid+1, high);	//sorting 2nd half
		marge(low, mid, high);	//marging the array again
	}
}
void margesort::show(int n){
	cout<<"Sorted Elements Are: "<<endl;	//showing sorted array
	for(int i=1; i<=n; i++) cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n;
	margesort m;	//creating a object
	cout<<"Enter the Array Size: "<<endl; //array size
	cin>>n;
	cout<<"Enter The Elements: "<<endl;		//array elements
	for(int i=0; i<n; i++) cin>>a[i];
	m.marge_sort(0, n);
	m.show(n);
	return 0;
}