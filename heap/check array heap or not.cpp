#include <bits/stdc++.h> 
using namespace std; 
#include<iostream>

bool isHeap(int arr[],  int n) 
{ 
 
    for (int i=0; i<=(n-2)/2; i++) 
    { 
        // If left child is greater, return false 
        if (arr[2*i +1] > arr[i]) 
                return false; 
  
        // If right child is greater, return false 
        if (2*i+2 < n && arr[2*i+2] > arr[i]) 
                return false; 
    } 
    return true; 
} 
  
int main() 
{ 
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3}; 
    int n = sizeof(arr) / sizeof(int); 
  
    isHeap(arr, n)? printf("Yes"): printf("No"); 
  
    return 0; 
}
