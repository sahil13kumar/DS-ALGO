

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

// function to fill the map

void fillMap(Node* root, int level,int hd,map<int, pair<int,int>>& mp){
	
	if(root==NULL)	return;
	
	if(!mp.count(hd)){
		mp[hd] = {root->data,level};
	}
	else if(mp[hd].second <= level){
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


/*
void topView(struct Node* root){
	
	if(root==NULL)	return;
	
	queue<pair<Node*,int>> q;
	map<int,int> mp;
	
	q.push({root,0});
	
	while(q.size()){
		
		Node* temp = q.front().first;
		int hd = q.front().second;
		
		q.pop();
		
		mp[hd] = temp->data;
		if(temp->left)
			q.push({temp->left,hd-1});
		if(temp->right)
			q.push({temp->right,hd+1});
	}
	
	for(auto x:mp){
		cout<<x.second<<" ";
	}
}
*/


// Driver code
int main()
{

  Node * root = newNode(20);
  root -> left = newNode(8);
  root -> right = newNode(22);
  root -> left -> left = newNode(5);
  root -> left -> right = newNode(3);
  root -> right -> left = newNode(4);
  root -> right -> right = newNode(25);
  root -> left -> right -> left = newNode(10);
  root -> left -> right -> right = newNode(14);
	cout << "Following are nodes in top view of Binary "
			"Tree\n";
	topView(root);
	return 0;
}


/*
Input:              20
                    /     \
                8         22
             /     \     /     \
          5        3  4      25
                  /    \      
              10       14
Output: 5 10 4 14 25. 
Explanation: If there are multiple bottom-most nodes for a horizontal distance from the root, 
then print the later one in the level traversal. 3 and 4 are both the bottom-most nodes at a horizontal distance of 0, we need to print 4. 
*/
