



void merge(int a[],int l,int m,int r){
	
	int n1 = m-l+1,n2 = r-m;
//	int i=0,j=0;
	
	int L[n1],R[n2];
	
	for(int i=0;i<n1;i++)
		L[i] = a[l+i];
	for(int j=0;j<n2;j++)
		R[j] = a[m+j+1];
		
	int i=0,j=0;
	int k = l;
	
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;	
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		a[k++] = L[i++];
	}

	while(j<n2){
		a[k++] = R[j++];
	}

}



void mergeSort(int a[], int l,int r){
	
	if(l<r){
		int m = l+(r-l)/2;
		
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void printArray(int A[], int size) 
{ 
    for(int i = 0; i < size; i++) 
        cout << A[i] << " "; 
} 


int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Given array is \n"; 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "\nSorted array is \n"; 
    printArray(arr, arr_size); 
    return 0; 
}  
