#include<bits/stdc++.h> 
using namespace std; 


int cutRod(int arr[],int n){
	
	int val[n+1];
	val[0] = 0;
	int i,j;
	
	for(i=1;i<=n;i++){
		
		int max1 = INT_MIN;
		for(j=0;j<i;j++){
			max1 = max(max1,arr[j]+val[i-j-1]);
		}
		val[i] = max1;
	}
	
	return val[n];
}


int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size)); 
    getchar(); 
    return 0; 
}  
