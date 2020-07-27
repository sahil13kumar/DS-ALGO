#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

vector<int> ar[10001];
int vis[10001],col[10001];


bool dfs(int node,int par){
	
	vis[node] = 1;
	for(int child:ar[node]){
		
		if(vis[child]==0){
			if(dfs(child,node) == true)
				return true;
		}
		else{
			if(child!=par)
				return true;
		}
	}
	return false;
}

int main(){

	int n,i,e,a,b,q;
	cin>>n>>e;
	
	for(int i=1;i<=n;i++)
		ar[i].clear() , vis[i] = 0;
		
	for(int i=1;i<=e;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

	
	if(dfs(1,0))
		cout<<"YES cycle\n";
	else 
		cout<<"NO cycle\n";
	
}	
