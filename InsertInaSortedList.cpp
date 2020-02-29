#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int val;
	Node *next;	
	Node(int val){
		this->val=val;
		this->next=NULL;
	}
};
class Solution{
	
	public:
	Node* insert(Node *head,int val){
		Node *nn=new Node(val);
		if(!head) return nn;
		Node *ptr=head;
		while(ptr->next) ptr=ptr->next;
		ptr->next=nn;
		return head;
	}
	
	void display(Node *head){
		Node *ptr=head;
		while(ptr){
			cout << ptr->val << " ";
			ptr=ptr->next;
		}
		cout << "\n";
	}
	
	Node *swap(Node *a,Node *b){
		a->next=b;
		b->next=a;
		return b;
	}
	
	Node *InsertSorted(Node *head, Node *element){
		Node *new_head=head;
		if(!head || head->val>=element->val){
			element->next=head;
			new_head=element;
		}
		else{
			Node *curr=head;
			Node *pre=NULL;
			while(curr && curr->val<element->val){
				pre=curr;
				curr=curr->next;
			}
			pre->next=element;
			element->next=curr;
		}
		
      return new_head;
	}
	
	Node *InsertionSort(Node *head){
		if(!head || !head->next) return head;
		Node *sorted=NULL;
		Node *curr=head;
		while(curr){
			Node *next=curr->next;
			sorted=InsertSorted(sorted,curr);
			curr=next;
		}
		
		return sorted;
		
	}
	
};

int main(){
	int n;
	cin >> n;
	Node *head=NULL;
	Solution A;
	for(int i=0;i<n;i++){
		int in;
		cin >> in;
		head=A.insert(head,in);
		
	}
	// A.display(head);
	// int val;
	// cin >> val;
	Node *element=new Node(val);
	head=A.InsertionSort(head);
	A.display(head);

	
}