//https://www.spoj.com/problems/BUGLIFE/
#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

vector<int> ar[10001];
int vis[10001],col[10001];


bool dfs(int node,int c){
	
	vis[node] = 1;
	col[node] = c;
	
	for(int child : ar[node]){

		if(vis[child]==0){
			bool res = dfs(child , c^1);
			if(res==false)
				return false;
		}else{
			if(col[node]==col[child])
				return false;
		}		
	
	}
			
	return true;
}

int main(){

	int n,i,e,a,b,q;
	cin>>n>>e;
	
	for(int i=1;i<=n;i++)
		ar[i].clear() , vis[i] = 0;
		
	for(int i=1;i<=e;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

	
	bool flag = true;
	
	for(i=1;i<n;i++)
		if(vis[i]==0){
			bool res = dfs(i,0);
			
			if(res==false) flag=false;
		}
			
	if(flag) cout<<"YES - bipartite-graph\n";
	else cout<<"NO - bipartite-graph\n";
}	
