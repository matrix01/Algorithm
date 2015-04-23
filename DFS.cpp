#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

#define white 0
#define gray 1
#define black 2
#define max 1000

int a[10000];
int color[max], vertex, edge;
int visit[max], count1;
bool visited[max];

void dfs_visit(vector<int>g[], int u){
	color[u]=gray;
	for(int v=0; v<g[u].size(); v++){
		if(color[g[u][v]]==white){
			dfs_visit(g, g[u][v]);
		}
	}
	count1++;
	color[u]=black;
}

void dfs(vector<int>g[]){
	for(int i=0; i<=vertex; i++)
		color[i]=white;
	for(int u=1; u<=vertex; u++){
		if(color[u]==white)
			dfs_visit(g, u);
	}
}
int main(){
	vector<int>g[max];
	int t;
	cin>>t;
	while(t--){
		//g[max].clear();
		cin>>edge;
		int u, v;
		memset(a, 0, sizeof(a));
		for(int i=0; i<edge; i++){
			cin>>u>>v;
			g[u].push_back(v);
			a[u]++;
			a[v]++;
		}
		int count=0;
		for(int i=0; i<edge*2; i++)
			if(a[i]!=0)count++;
		//cout<<count;
		vertex=count;
		count1=0;
		dfs(g);
		cout<<count1<<endl;
	}
	return 0;
}