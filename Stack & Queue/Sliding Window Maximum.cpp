


void printKMax(int a[],int n,int k){
	
	deque<int> q(k);
	int i;
	for(i=0;i<k;i++){
		while(q.size() && a[i]>=a[q.back()]) 
			q.pop_back();
		
		q.push_back(i);
	}

	for(i=k;i<n;i++){
		
		cout<<a[q.front()]<<" ";
		
		while(q.size() && a[q.front()]<=i-k) 
			q.pop_front();
		
		while(q.size() && a[i]>=a[q.back()]) 
			q.pop_back();
		
		q.push_back(i);
		
	}
	
	cout<<a[q.front()]<<" ";
}



int main() 
{ 
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    printKMax(arr, n, k); 
    return 0; 
} 
