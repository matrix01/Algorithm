#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int weight;
    unsigned char value;
    const node *child0;
    const node *child1;
    node( unsigned char c = 0, int i = -1 ) {
        value = c;
        weight = i;
        child0 = 0;
        child1 = 0;
    }
    node( const node* c0, const node *c1 ) {
        value = 0;
        weight = c0->weight + c1->weight;
        child0 = c0;
        child1 = c1;
    }
    bool operator<( const node &a ) const {
        return weight >a.weight;
    }
    void traverse(string code="") const {
    if ( child0 ) {
        child0->traverse( code + '0' );
        child1->traverse( code + '1' );
    } else {
        cout <<" " <<value <<"      ";
        cout <<weight;
        cout <<"   " <<code <<endl;
    }
}
};
void count_chars( int *counts )
{
    string sent;
	getline(cin,sent);
	for(int i=0; i<256; i++) counts[i]=0;
	int l=sent.length();
	for(int i=0; i<l; i++)
		counts[sent[i]]++;
}
 
int main()
{
    int counts[ 256 ];
    count_chars( counts );
    priority_queue < node > q;
     for ( int i = 0 ; i <256 ; i++ )
        if ( counts[ i ] )
            q.push( node( i, counts[ i ] ) );
    while ( q.size() >1 ) {
        node *child0 = new node( q.top() );
        q.pop();
        node *child1 = new node( q.top() );
        q.pop();
        q.push( node( child0, child1 ) );
    }
     cout <<"CHAR  FREQUENCY  HOFFMAN-CODE" <<endl;
    q.top().traverse();
    return 0;
}