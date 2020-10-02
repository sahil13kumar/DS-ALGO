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




// IN 1D array
// Coin Change Permutation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
    int i,j;  
        
    int dp[amount+1],n = coins.size(); 
  
    dp[0] = 0; 
  
    for (i=1; i<=amount; i++) 
        dp[i] = INT_MAX; 
        
	
	for(i=1;i<=amount;i++){
		for(j=0;j<n;j++){
			
			if(coins[j]<=i){
				int sub_res = dp[i-coins[j]];
				if(sub_res!=INT_MAX && sub_res+1< dp[i])
					dp[i] = sub_res+1;
			}
		}
	}    
        
        return (dp[amount]!=INT_MAX? dp[amount] : -1);
    }
};








//Coin Change Combination


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
    int n = coins.size();
        
    int dp[amount+1];
	memset(dp, 0, sizeof(dp)); 
	dp[0] = 1;
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=coins[i];j<=amount;j++){
			dp[j] += dp[j-coins[i]];
		}
	}
	
	return dp[amount];
        
    }
};
