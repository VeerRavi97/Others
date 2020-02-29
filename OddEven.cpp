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
	
	Node *oddeven(Node *head){
		
		if(!head || !head->next) return head;
		Node *odd_head=NULL;
		Node *even_head=NULL;
		Node *ptr1=nullptr;
		Node *ptr2=nullptr;
		Node *curr=head;
		while(curr){
			int val=curr->val;
			if(val&1){
				if(!ptr1) {
					odd_head=curr;
					ptr1=odd_head;
					
				}	
				else{
					ptr1->next=curr;
					ptr1=ptr1->next;
				}
				
			}
			else{
				if(!ptr2) {
					even_head=curr;
					ptr2=even_head;
				}
				else {
					ptr2->next=curr;
				ptr2=ptr2->next;
				}
				
			}
			curr=curr->next;
		}
		ptr2->next=NULL;
		//display(odd_head);
		//display(even_head);
		if(odd_head){
			ptr1->next=even_head;
			return odd_head;
		}
		return even_head;
		
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
	//A.display(head);
	head=A.oddeven(head);
	A.display(head);

	
}