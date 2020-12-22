#include <iostream>
using namespace std;
#include<bits/stdc++.h>

//  https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

struct edge{
	int a,b,w;
};

edge ar[10000];
int par[10000];

bool comp(edge a,edge b){
	if(a.w < b.w)
		return true;
	return false;
}

int find(int a){
	if(par[a] == -1) return a;
	
	return par[a] = find(par[a]);
}

void merge(int a,int b){
	par[a] = b;
}

int main(){
	
	int n,i,m,a,b,w;
	cin>>n>>m;
	
	for(i=0;i<n;i++)
		par[i] = -1;
	
	for(i=0;i<m;i++){
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	}
	
	sort(ar,ar+m,comp);
	int sum=0;
	
	for(i=0;i<m;i++){
		a = find(ar[i].a);
		b = find(ar[i].b);
		
		if(a!=b){
			sum+=ar[i].w;	
			merge(a,b);
		}	
	}
	
	
	cout<<sum;
}




