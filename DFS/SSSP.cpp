// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/
//   practice-problems/algorithm/bishu-and-his-girlfriend/

#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)	
//SSSP using dfs only work in tree only

vector<int> ar[10001];
int vis[10001],dis[10001];


void dfs(int node,int c){
	
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

	int n,e,a,b,q;
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
			
	if(res) cout<<"YES\n";
	else cout<<"NO\n";
}	
	
