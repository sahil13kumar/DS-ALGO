#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node {
	Node* left;
	Node* right;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

void fillMap(Node* root, int level,int hd,map<int, pair<int,int>>& mp){
	
	if(root==NULL)	return;
	
	if(!mp.count(hd)){
		mp[hd] = {root->data,level};
	}
	//Check if this value of hd is already present and its vertical distance is greater than level, then set map[hd] equal to {root->data, level}
	else if(mp[hd].second > level){
		mp[hd] = {root->data,level};
	}
	
	fillMap(root->left,level+1,hd-1,mp);
	fillMap(root->right,level+1,hd+1,mp);
}


void topView(struct Node* root)
{
	map<int, pair<int,int> > mp;
	
	fillMap(root,0,0,mp);
	for(auto x:mp){
		cout<<x.second.first<<" ";
	}
}

// Driver code
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Following are nodes in top view of Binary "
			"Tree\n";
	topView(root);
	return 0;
}






/*
void topView(struct Node* root){
	
	if(root==NULL)	return;
	queue<pair<Node*,int>> q;	
	q.push({root,0});
	map<int,int> mp;
	
	while(q.size()){
		
		Node* temp = q.front().first;
		int level = q.front().second;
		q.pop();
		
		if(!mp.count(level))	{
			mp[level] = temp->data;
		}
		
		if(temp->left)
			q.push({temp->left,level-1});
		if(temp->right)
			q.push({temp->right,level+1});
	}
	
	for(auto x:mp){
		cout<<x.second<<" ";
	}
}
*/
