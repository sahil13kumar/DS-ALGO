#include <bits/stdc++.h>
using namespace std;
#include<iostream> 

int r,c;
bool vis[1000][1000];
char a[1000][1000];


bool isvalid(int x,int y){
	
	if(x<1 || x>r || y<1 || y>c) return false;
	
	if(vis[x][y]==true || a[x][y]=='#') return false;
	
	return true;
}



int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y){
	
	vis[x][y] = 1;
	int i,j;
	
	for(i=0;i<4;i++)
		if(isvalid(x+dx[i], y+dy[i]))
			dfs(x+dx[i], y+dy[i]);		
}


int main(){
	
	int i,j;

	cin>>r>>c;

	
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
	
	int cnt=0;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]=='.' && vis[i][j]==false)
				dfs(i,j) ,cnt++;
		}
	}
	
	cout<<"Total Rooms :"<<cnt<<endl;
}




//https://cses.fi/problemset/task/1192/
