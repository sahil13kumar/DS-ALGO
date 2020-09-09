
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool isPrime(int n){
	int i;
	if(n<=1) return false;
    
	for(i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}


int main(){

    int max1 = 10001;

    int l,r,i,j;
    cin>>l>>r;
    

    for(i=l;i<=r;i++){

    	if(isPrime(i))
    		cout<<i<<" ";
    }

}
