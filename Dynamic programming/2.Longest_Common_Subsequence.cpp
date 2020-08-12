#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

int lcs(char* X,char* Y,int m,int n ){
	
	int i,j;
	int dp[m+1][n+1];
	
	for(i=0;i<=m;i++) dp[i][0] = 0;
	
	for(i=1;i<=n;i++) dp[0][i] = 0;
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			
			if(X[i-1]==Y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}	
	}
	
	return dp[m][n];
}

int main()  
{  
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
      
    int m = strlen(X);  
    int n = strlen(Y);  
      
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;  
      
    return 0;  
} 
