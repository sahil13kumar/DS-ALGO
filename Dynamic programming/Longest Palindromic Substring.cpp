
int longestPalSubstr(string st){
	
	int i,j,g,len=0,n = st.length();
	int dp[n][n],start,c=0;
	
	for(g=0;g<n;g++){
		
		for(i=0,j=g;j<n;i++,j++){
			
			if(g==0){
				dp[i][j] = 1;
			}
			else if(g==1){
				if(st[i]==st[j])
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			else{
				if(st[i]==st[j] && dp[i+1][j-1]==1)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			
			if(dp[i][j]){
				len = g+1;
				start = i;
				cout<<st.substr(start,len)<<endl;
				c++;
			}
				
		}
	}
	
	cout<<"Total Palindromic Substring Count :"<<c<<endl;
	cout<<"Longest Palindromic Substring :"<<st.substr(start,len)<<endl;
	return len;	
}




int main() 
{ 
    string str = "abaab"; 
    cout << "\nLongest Palindromic Substring of Length is: "
         << longestPalSubstr(str); 
    return 0; 
} 
