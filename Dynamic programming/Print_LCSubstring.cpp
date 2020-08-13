#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

void printLCSubStr(char *X,char *Y,int m,int n){
	
	int dp[m+1][n+1],i,j;
	int len=0,row,col;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(X[i-1]==Y[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;

				if(len< dp[i][j]){
					len = dp[i][j];
					row=i;
					col=j;
				}
			}else{
				dp[i][j] = 0;
			}		 
		}
	}
	
	if(len==0) 
		cout<<"No substring present";
	
	string str="";
	while(dp[row][col]!=0){
		str+=X[row-1];
		row--;
		col--;
	}

	cout<<str;
}

int main() 
{ 
    char X[] = "babad"; 
    char Y[] = "dabab"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    printLCSubStr(X, Y, m, n); 
    return 0; 
} 
