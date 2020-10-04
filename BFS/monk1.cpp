#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define int long long
vector<int> ar[1000001];
int vis[1000001],dist[1000001];

void BFS(int src){
	queue<int> q;
	q.push(src);
	vis[src]= 1;
	dist[src] = 0;
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		for(int child: ar[curr]){
			if(vis[child]==0){
				
				q.push(child);
				dist[child] = dist[curr]+1;
				vis[child] = 1;
			}
		}	
	}
	
}

int main(){
	int t,n,m,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		
		for(int i=1;i<=n;i++) {
			ar[i].clear();
			vis[i] = 0;
		}
		
		while(m--){
			cin>>a>>b;
			ar[a].push_back(b);
			ar[b].push_back(a);
		}
			BFS(1);
			
		
			cout<<dist[n]<<endl;	
	}
	
}
