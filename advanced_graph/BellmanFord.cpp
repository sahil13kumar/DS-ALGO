#include <iostream>
using namespace std;
#include<bits/stdc++.h>
//https://www.geeksforgeeks.org/bellman-ford-algorithm-simple-implementation/

int main(){
	int v=5,e=8;
	
	
	int graph[8][3] = { { 0, 1, -1 }, { 0, 2, 4 }, 
                       { 1, 2, 3 }, { 1, 3, 2 },  
                       { 1, 4, 2 }, { 3, 2, 5 },  
                       { 3, 1, 1 }, { 4, 3, -3 } }; 	
    
    int j,i;
    int dis[v+1]; 
    for (i = 0; i < v; i++) 
        dis[i] = INT_MAX; 

    dis[0] = 0;
    
    for(i=0;i<v-1;i++){
		for(j=0;j<e;j++){		
			if(dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
				dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
		}	
	}
	
	for (int i = 0; i < e; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && 
                   dis[x] + weight < dis[y]) 
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl; 
    } 
  
    cout << "Vertex Distance from Source" << endl; 
    for (int i = 0; i < v; i++) 
        cout << i << "\t\t" << dis[i] << endl;
}


