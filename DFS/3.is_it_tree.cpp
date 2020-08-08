// https://www.spoj.com/problems/PT07Y/

#include <bits/stdc++.h>
using namespace std;
#include<iostream>	


vector<int> ar[10001];
int vis[10001],dis[10001];


void dfs(int node){
	
	vis[node] = 1;
	
	for(int child : ar[node])
		if(vis[child]==0)
			dfs(child);
	
}

int main(){
	fast;
	int n,e,a,b,q;
	cin>>n>>e;
	
	for(int i=1;i<=n-1;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);


	int cc_count = 0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
			dfs(i), cc_count++;
	}
	
	if(cc_count==1 && e == n-1)
		cout<<"YES\n";
	else 
		cout<<"NO\n";

	return 0;
}	
	
