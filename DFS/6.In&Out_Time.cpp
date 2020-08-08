





int timer=1;

void dfs(int node){
	
	vis[node] = 1;
	
	in[node] = timer++;
	for(int child : ar[node])
		if(vis[child]==0)
			dfs(child);
	
	out[node] = timer++;
}
