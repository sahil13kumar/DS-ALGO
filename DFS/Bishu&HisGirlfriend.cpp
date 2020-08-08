
#include <bits/stdc++.h>
using namespace std;
#include<iostream>
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)	
//SSSP using dfs only work in tree only

vector<int> ar[10001];
int vis[10001],dis[10001];


void dfs(int node,int d){
	
	vis[node] = 1;
	dis[node] = d;
	for(int child : ar[node])
		if(vis[child]==0)
			dfs(child,dis[node]+1);
	
}

int main(){
	fast;
	int n,a,b,q;
	cin>>n;
	
	for(int i=1;i<=n-1;i++)
		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);

	
	dfs(1,0);
	
	cin>>q;	
	int min1=INT_MAX,ans=-1;
	
	while(q--){
		int girl_city;
		cin>>girl_city;
		
		if(dis[girl_city]<min1) 
			min1 = dis[girl_city], ans = girl_city;
		else
			if(dis[girl_city]==min1 && girl_city<ans)
				ans = girl_city;
	}
	
	cout<<ans;
}	









// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/description/
