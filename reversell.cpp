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
	
	Node *reverse(Node *head){
		
		if(!head || !head->next) return head;
		Node* curr=head;
		Node*pre=nullptr;
		Node *next=nullptr;
		while(curr){
			// cout << "Inside " << curr->val << "\n";
			next=curr->next;
			curr->next=pre;
			pre=curr;
			curr=next;
		}
     return pre;
	}
	
};

int main(){
	int n;
	cin >> n;
	Node *head=NULL;
	Solution A;
	for(int i=0;i<n;i++){
		int in;0
		cin >> in;
		head=A.insert(head,in);
		
	}
	// A.display(head);
	head=A.reverse(head);
	A.display(head);

	return 0;
	
}