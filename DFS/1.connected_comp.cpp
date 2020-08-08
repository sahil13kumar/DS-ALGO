#include <bits/stdc++.h>
using namespace std;
#include<iostream>
	
vector<int> ar[100001];
int vis[100001];


void dfs(int node){
	
	vis[node] = 1;
	
	for(int child:ar[node]){
		if(!vis[child])
			dfs(child);
	}
}

int main(){
	
	int i,n,e,a,b,count=0;
	cin>>n>>e;
	
	for(i=1;i<=e;i++){
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i])
			dfs(i), count++;
		
	}
	
	cout<<count;
}	
	
