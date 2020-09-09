#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define MAX1 90000000 
#define int long long
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool a[MAX1];

void SieveOfEratosthenes(vector<int> &primes){
	
	a[0]=true,a[1]=true;
	int i,j;
	for(i=2;i*i<=MAX1;i++){
		
		if(a[i]==false){
			for(j=i*i;j<=MAX1;j+=i){
				a[j] = true;			
			}
		}		
	}
		
	for(int i=2;i<=MAX1;i++){
		if(a[i]==false)
			primes.push_back(i);	
	}
			
}


int32_t main(){
	fast;
	vector<int> primes; 
	
	int t,n;
	cin>>t;
	      
    SieveOfEratosthenes(primes);
	

	while(t--){
		
		cin>>n;
		cout<<primes[n-1]<<endl;		
	
	}
    
}
