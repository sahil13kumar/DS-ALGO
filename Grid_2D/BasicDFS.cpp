#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

vector<int> ar[100001];
bool vis[1001][1001];
int N,M;

bool isValid(int x,int y){
	
	if(x<1 || x>N || y<1 || y>M) return false;
	
	if(vis[x][y]==true) return false;
	
	return true;
}

void dfs(int x,int y){
	
	vis[x][y] = 1;
	
	cout<<x<<" "<<y<<endl;
	
	if(isValid(x-1,y)) dfs(x-1,y);
	
	if(isValid(x,y+1)) dfs(x,y+1);
	
	if(isValid(x+1,y)) dfs(x+1,y);
	
	if(isValid(x,y-1)) dfs(x,y-1);
}



int main(){
	cin>>N>>M;
	
	dfs(1,1);
}
