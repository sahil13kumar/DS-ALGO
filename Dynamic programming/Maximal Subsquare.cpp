#include <iostream>
#include<bits/stdc++.h>
using namespace std;

 
int maximalSquare(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
        
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
                
			if (i==0 || j==0) {
                dp[i][j] = matrix[i][j];
            }
                
            if (i > 0 && j > 0 && matrix[i][j] == 1) {
                int small_square_size = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                dp[i][j] = max(dp[i][j], small_square_size);
            }
        }
    }
        
        
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
                
			cout<<dp[i][j]<<" ";
            }
        cout<<"\n";
    }
        
    int result = 0;
        
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            result = max(result, dp[i][j]);
        }
    }
        
    return result * result;
    
}

int main(){
	
	
	vector<vector<int>> mat=
					{{0, 1, 1, 0, 1},  
                    {1, 1, 0, 1, 0},  
                    {0, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 0},  
                    {1, 1, 1, 1, 1},  
                    {0, 0, 0, 0, 0}}; 
                    
    cout<<maximalSquare(mat);
}

