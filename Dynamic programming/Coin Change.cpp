#include<bits/stdc++.h> 
using namespace std; 

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
