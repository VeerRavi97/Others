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
	
	Node *SwapPairs(Node *head){
		
		if(!head || !head->next) return head;
		Node *current=head->next->next;
		Node *pre=head;
		head=head->next;
		head->next=pre;
		while(current && current->next){
			//cout << current->val << "\n";
			Node *next=current->next->next;
			current->next->next=current;
			pre->next=current->next;
			pre=current;
			current=next;
		}
	
		pre->next=current;
       
		return head;
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
	head=A.SwapPairs(head);
	A.display(head);

	
}