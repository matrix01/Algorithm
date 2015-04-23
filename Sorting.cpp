#include<iostream>
#include<ctime>
using namespace std;


class sorter{
int *a;
int size;
void swap(int, int);
public:
sorter();
void generate_input();
void selection_sort();
void insertion_sort();
void bubble_sort();
void quick_sort(int , int);
void show();
int bin_search(int , int , int );
~sorter();
int get_size(){return size;}
};
sorter::sorter()
{
size = 10000;
a = new int[size];
}

sorter::~sorter()
{
delete []a;
}

void sorter::generate_input()
{
for(int i = 0;i<size;i++)
a[i] = rand()%30000;
}

void sorter::selection_sort()
{
for(int i = 0;i<size;i++)
{
int k = i;
for(int j = i+1;j<size;j++)
if(a[j]<a[k])
k = j;
swap(i,k);
}
}

void sorter::insertion_sort()
{
for(int i = 0;i<size;i++)
{
int key = a[i];
int j = i - 1;
while(j >= 0 && a[j] > key)
{
a[j+1] = a[j];
j--;
}
a[j+1] = key;
}
}


void sorter::bubble_sort()
{
for(int i = 0;i<size;i++)
{
for(int j = i+1;j<size;j++)
if(a[j]<a[i])
swap(i,j);
}
}

void sorter::quick_sort( int l, int r)
{
if(r<l)
return;
int x = a[l];
int i = l;
int j = i + 1;
for(;j<=r;j++)
if(x > a[j])
swap(++i, j);
swap(i, l);
quick_sort(l, i-1);
quick_sort(i+1, r);
}

void sorter::swap(int i, int j)
{
int t = a[i];
a[i] = a[j];
a[j] = t;
}

void sorter::show()
{
for(int i = 0;i<size;i++)
cout<<a[i]<<" ";
cout<<endl;
}

int sorter::bin_search(int l, int r, int x)
{
while(l<=r)
{
int m = (l + r)/2;
if(x == a[m])
return m;
else if(x < a[m])
r = m - 1;
else
l = m + 1;
}
if(l>r)
return -1;
}

void main()
{
clock_t t1, t2;

sorter s; 
s.generate_input();
t1 = clock();
s.bubble_sort();
t2 = clock();
cout << (double)(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms.\n";

sorter t;
t.generate_input();
t1 = clock();
t.insertion_sort();
//t.quick_sort(0,t.get_size()-1);
t2 = clock();
cout << (double)(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms.\n";


/*
s.show();
cout<<"enter a number to search:";
int x;
cin>>x;
int result = s.bin_search(0, s.get_size()-1, x);
if(result == -1)
cout<<x<<" is not found\n";
else
cout<<x<<" is found at "<<result<<endl;*/

}