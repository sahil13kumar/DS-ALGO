#include <bits/stdc++.h>
using namespace std;
#include<iostream>  
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"


int findPeak(int a[],int n){
	int l =0,r = n-1;
	
	while(l<=r){
		int mid = l+(r-l)/2;
		int prev = max(0,mid-1);
		int next = min(mid+1,n-1);
		
		if(a[prev]<=a[mid] && a[next]<=a[mid]){
			return mid;
		}else if(a[prev]<a[next]){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}	
	return -1;
}

int binary_search(int a[],int l,int r,int x){
	
	while(l<=r){
		int mid = l+(r-l)/2;
		
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
			return binary_search(a,mid+1,r,x);
		else
			return binary_search(a,l,mid-1,x);
	}
	return -1;
}


int find_piovot(int a[],int n,int k){
	
	int pick = findPeak(a,n);
	
	if(pick==-1)
		return binary_search(a,0,n-1,k);
	
	if(a[pick]==k)
		return pick;
		
	if(a[0]<pick)
		return binary_search(a,0,pick-1,k);
	return binary_search(a,pick+1,n-1,k);
}

int main() 
{ 
    int arr[] = { 8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 }; 
    int k=0,n = sizeof(arr) / sizeof(arr[0]); 
    
    cout<<findPeak(arr,n,k);
    

    return 0; 
} 
