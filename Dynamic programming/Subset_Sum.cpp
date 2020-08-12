#include <bits/stdc++.h>
using namespace std;
#include<iostream>	

bool isSubsetSum(int set[],int n,int sum){
	
	bool subset[n+1][sum+1];
	int i,j;
	for(i=0;i<=n;i++){
		subset[i][0]=true;
	}
	for(i=1;i<=sum;i++){
		subset[0][i]=false;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			
			if(j < set[i-1])
				subset[i][j] = subset[i-1][j];
			if(j >= set[i-1])
				subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
		}
	}
	    
	/*
    for (int i = 0; i <= n; i++) 
    { 
       	for (int j = 0; j <= sum; j++) 
          	printf ("%4d", subset[i][j]); 
       	printf("\n"); 
    }*/
	return subset[n][sum];
}

int main() 
{ 
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 9; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum) == true) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0; 
}
