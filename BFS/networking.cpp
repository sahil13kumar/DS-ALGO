#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> ar[100001];
int level[100001],vis[100001],dist[100001];


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
				level[dist[child]]++;
			}
		}	
	}
	
}


int main(){
	
	int i,a,b,n,e,q;
	cin>>n>>e;
	
	for(i=1;i<=e;i++){
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	

	cin>>q;
	while(q--){
		int src,d;
		cin>>src>>d;
		for(i=0;i<=n;i++){
		level[i] = 0, vis[i] = 0;
		}
		BFS(src);
		
		cout<<level[d];	
	}
}
