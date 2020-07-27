#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

vector<int> ar[10001];
int vis[10001],subSize[10001];


int dfs(int node){
	
	vis[node] = 1;
	int cur_size=1;
	
	for(int child:ar[node]){	
		if(vis[child]==0){
			cur_size+= dfs(child);
		}
	}
	subSize[node] = cur_size;
	
	return cur_size;
}

int main(){

	int n,i,e,a,b;
	cin>>n>>e;
	
//	for(int i=1;i<=n;i++)
//		ar[i].clear() , vis[i] = 0;
		
	for(int i=1;i<=e;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

	
	dfs(1);
	
	for(i=1;i<=n;i++){
		cout<<subSize[i]<<" ";
	}
	
}	
