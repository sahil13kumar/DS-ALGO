#include <iostream>
using namespace std;
#include<bits/stdc++.h>

struct Node{
	Node* next;
	int data;
};

void push(Node** head,int data){
	Node* temp = new Node; 
	temp->data = data;
	temp->next = *head;
	*head = temp;
}


void printList(Node* a){
	
	while(a!=NULL){
		cout<<a->data<<" ";
		a=a->next;
	}
}

Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
}


void FrontBackSplit(Node* root,Node** a,Node** b){

	Node* slow = root;
	Node* fast = root->next;
	
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	
	*a = root;
	*b = slow->next;
	slow->next = NULL; 
}

void MergeSort(Node** headRef) 
{ 
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    FrontBackSplit(head, &a, &b); 
  
    MergeSort(&a); 
    MergeSort(&b); 
  
    *headRef = SortedMerge(a, b); 
} 




int main() 
{ 
    Node* res = NULL; 
    Node* a = NULL; 

    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  	printList(a); 
	cout<<endl;
    MergeSort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
  
    return 0; 
} 


