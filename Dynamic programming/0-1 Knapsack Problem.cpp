#include <bits/stdc++.h>
using namespace std;
#include<iostream>	
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int knapSack(int W,int wt[],int val[],int n){
	
	int i,j,dp[n+1][W+1];
	
	for(i=0;i<=n;i++){
		for(j=0;j<=W;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(j<wt[i-1]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j] ,val[i-1]+dp[i-1][j-wt[i - 1]]);
			}
		}
	}
	
	return dp[n][W];
}


int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 
