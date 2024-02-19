



void getVerticalOrder(Node* root,int hd, map<int, vector<int>> &mp){
	
	if(root==NULL) return;
	
	mp[hd].push_back(root->key);
	
	getVerticalOrder(root->left,hd-1,mp);
	getVerticalOrder(root->right,hd+1,mp);
	
}


void printVerticalOrder(Node* root){
	
	map<int,vector<int> > mp;
	int hd = 0;
	
	getVerticalOrder(root,hd,mp);
	
	for(auto p1:mp){
		sort(p1.second.begin(),p1.second.end());
		vector<int> v = p1.second;
		for(auto p2:v){
			cout<<p2<<" ";
		}
		cout<<endl;
	}
	
}




//---------------------------------------------------------------------------------------
//Print a Binary Tree in Vertical Order (using level order traversal)



void printVerticalOrder(Node* root){
	
	if(root==NULL) return;
	
	map<int,vector<int> > mp;
	queue<pair<Node*,int>> q;
	int hd = 0;
	
	q.push({root,hd});
	
	while(!q.empty()){
		
		pair<Node*,int> temp = q.front();
		q.pop();
		Node* head = temp.first;
		hd = temp.second;
		
		mp[hd].push_back(head->key);
		
		if(head->left!=NULL)
			q.push({head->left,hd-1});
		if(head->right!=NULL)
			q.push({head->right,hd+1});
	}
	
	for(auto p1:mp){
		for(auto p2:p1.second){
			cout<<p2<<" ";
		}
		cout<<endl;
	}
}
