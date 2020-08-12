#include<bits/stdc++.h> 
using namespace std; 


/*
int count(int set[],int n,int sum){
	
	int dp[n+1][sum+1];
  
    for(int i = 0; i<=sum; i++)
         dp[0][i] = INT_MAX-1;
    
    for(int i = 1; i<=n; i++)
        dp[i][0] = 0;
        
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(j<set[i-1]){
                dp[i][j] = dp[i-1][j]; 
            }else{
              dp[i][j] = min(1+dp[i][j-set[i-1]],dp[i-1][j]);     
            }
        }
	}

	int ans  = dp[n][sum];
    if(ans==INT_MAX-1){
        return -1;
    }
    return ans;
}


int main() 
{ 
    int arr[] = {5,6,8}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 11; 
    cout<< count(arr, m, n); 
    return 0; 
} 
*/



#define MAX 9999
int count(int coins[],int m, int amount){
	
	if(amount==0) return 0;
	
	int dp[m+1][amount+1];
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=amount;j++){
			if(i==0 || j==0)
				dp[i][j] = MAX;
		}
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=amount;j++){
			if(j<coins[i-1])
				dp[i][j] = dp[i-1][j];
			else if(j == coins[i-1])
				dp[i][j] = 1;
			else
				dp[i][j] = min(dp[i-1][j-coins[i-1]]+1,dp[i-1][j]);
		}
	}
	
	if(dp[m][amount]==MAX)
		return -1;
		
	return dp[m][amount];
}

int main() 
{ 
    int i, j; 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", count(arr, m, 4)); 
    getchar(); 
    return 0; 
} 
