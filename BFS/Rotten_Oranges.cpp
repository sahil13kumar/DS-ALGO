#define R 3 
#define C 5 

bool isvalid(int i,int j){
	return (i>=0 && i<R && j>=0 && j<C);
}

struct ele{
	int x,y;
};

bool isDelim(ele temp){
	return (temp.x==-1 && temp.y==-1);
}


bool checkall(int arr[][C]) 
{ 
	for (int i=0; i<R; i++) 
	for (int j=0; j<C; j++) 
		if (arr[i][j] == 1) 
			return true; 
	return false; 
} 


int rotOranges(int a[R][C]){
		
	queue<ele> q;
	ele temp;
	int i,j,ans = 0;
	
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(a[i][j]==2){
				temp.x = i;
				temp.y = j;
				q.push(temp);
			}
		}
	}
	
	temp.x = -1;
	temp.y = -1;
	q.push(temp);
	
	
	while(!q.empty()){
		
		
		bool flag = false;
		
        // Process all the rotten oranges in current time frame. 
        while (!isDelim(q.front())) 
        { 
            temp = q.front(); 
			
          if (isvalid(temp.x+1, temp.y) && a[temp.x+1][temp.y] == 1) 
            { 
                if (!flag) ans++, flag = true; 
  
                a[temp.x+1][temp.y] = 2; 
  
                temp.x++; 
                q.push(temp); 
  
                temp.x--; 
            } 
            if (isvalid(temp.x-1, temp.y) && a[temp.x-1][temp.y] == 1) { 
                if (!flag) ans++, flag = true; 
                a[temp.x-1][temp.y] = 2; 
                temp.x--; 
                q.push(temp); // push this cell to Queue 
                temp.x++; 
            } 

            if (isvalid(temp.x, temp.y+1) && a[temp.x][temp.y+1] == 1) { 
                if (!flag) ans++, flag = true; 
                a[temp.x][temp.y+1] = 2; 
                temp.y++; 
                q.push(temp); // Push this cell to Queue 
                temp.y--; 
            } 

			if( isvalid(temp.x,temp.y-1) && a[temp.x][temp.y-1]==1){
				if(flag==false) flag = true,ans++;
				a[temp.x][temp.y-1]=2;
				temp.y--;
				q.push(temp);
				temp.y++;
			}			

			  
            q.pop();
		}
		
		q.pop();
		
		if(!q.empty()){
			temp.x = -1;
			temp.y = -1;
			q.push(temp);
		}
	}	
	
	return (checkall(a))?-1:ans;
}





int main() 
{ 
    int arr[][C] = { {2, 1, 0, 2, 1}, 
                     {1, 0, 1, 2, 1}, 
                     {1, 0, 0, 2, 1}}; 
    int ans = rotOranges(arr); 
    if (ans == -1) 
        cout << "All oranges cannot rotn"; 
    else
         cout << "Time required for all oranges to rot => " << ans << endl; 
    return 0; 
}  
