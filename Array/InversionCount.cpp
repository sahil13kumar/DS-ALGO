

int merge(int a[],int temp[],int l,int m,int r){
		
	int i=l,j=m;
	int k=l,inv_count = 0;
	
	while((i<=m-1) && (j<=r)){
		if(a[i]<=a[j]){
			temp[k++] = a[i++];	
		}
		else{
			temp[k++] = a[j++];
			inv_count+= (m-i);
		}
	}
	
	while(i<=m-1){
		temp[k++] = a[i++];
	}

	while(j<=r){
		temp[k++] = a[j++];
	}
	
	for(i=l;i<=r;i++)
		a[i] = temp[i];
	
	return inv_count;
}



int mergeSort(int a[], int temp[],int l,int r){
	int c = 0;
	if(l<r){
		int m = l+(r-l)/2;
		
		c+=mergeSort(a,temp,l,m);
		c+=mergeSort(a,temp,m+1,r);
		c+=merge(a,temp,l,m+1,r);
	}
	return c;
}

void printArray(int A[], int size) 
{ 
    for(int i = 0; i < size; i++) 
        cout << A[i] << " "; 
} 


int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5}; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
	int temp[arr_size];  
    cout<<mergeSort(arr,temp, 0, arr_size - 1); 
  
    cout << "\nSorted array is \n"; 
    printArray(arr, arr_size); 
    return 0; 
}  
