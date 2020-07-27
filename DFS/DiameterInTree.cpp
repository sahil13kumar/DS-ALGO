#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

vector<int> ar[10001];
int vis[10001],col[10001];

int maxD=INT_MIN,maxNode=-1;

void dfs(int node,int d){
	
	vis[node] = 1;
	if(d>maxD){
		maxD = d;
		maxNode = node;	
	} 
	
	for(int child:ar[node])	
		if(vis[child]==0)
			dfs(child,d+1);
}

int main(){

	int n,i,e,a,b;
	cin>>n>>e;
	
//	for(int i=1;i<=n;i++)
//		ar[i].clear() , vis[i] = 0;
		
	for(int i=1;i<=e;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

	maxD = -1;
	dfs(1,0);
	
	for(int i=1;i<=n;i++)
		vis[i] = 0;
	
	maxD = -1;
	dfs(maxNode,0);
	
	cout<<maxD;
}	
