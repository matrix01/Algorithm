/******************************
*	Program Name: Finding max and min value from array using devide and conquer method
*	By		: Milan
*	Date	: 23.05.2013
********************************/
#include<iostream>
#define MAX 10000
using namespace std;
class MAX_MIN{
	int a[MAX], max, min;	//declaring array and max min
public:
	void input(int);
	void find_max_min(int, int);
	void show();
};

void MAX_MIN::input(int s){
	cout<<"Enter Array Elements: "<<endl;	//taking inputs
	for(int i=0; i<s; i++) cin>>a[i];
	find_max_min(0, s-1);
}

void MAX_MIN::find_max_min(int l, int h){
	int mid, max1, min1;
	if(l==h)
		max=min=a[l]; //If the size of array is 1
	else if(l==h-1){
		if(a[l]>=a[h-1]){
			max=a[h];	// If the size of the array is 2
			min=a[l];
		}
		else{
			max=a[l];
			min=a[h];
		}
	}
	else{
		mid=(l+h)/2;	//dividing array
		find_max_min(l, mid);	//finding max min from 1st half
		max1=max;	//saving the values of prev max min in temp max min
		min1=min;
		find_max_min(mid+1, h); //finding max min from 2nd half
		if(max<max1) max=max1; //if the prev max is less than new max
		if(min>min1) min=min1;
	}
}

void MAX_MIN::show(){
	cout<<"Min: "<<min<<endl;
	cout<<"Max: "<<max<<endl;
}

int main(){
	int size;
	MAX_MIN M;
	cout<<"Enter the size of Array: "<<endl;	//taking array size
	cin>>size;
	M.input(size);
	M.show();
	return 0;
}