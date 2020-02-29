#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int val;
	Node *next;	
	Node *random;
	Node(int val){
		this->val=val;
		this->next=NULL;
		this->random=NULL;
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
			cout << ptr->val << " " << ptr->random->val << "\n" ;
			ptr=ptr->next;
		}
		cout << "\n";
	}
	
	Node *swap(Node *a,Node *b){
		a->next=b;
		b->next=a;
		return b;
	}
	
	Node *clone1(Node *head){
		
		unordered_map<Node*,Node*>mp;
		Node *curr=head;
		Node *cloned=NULL;
		Node *cloned_head=NULL;
		while(curr){
			Node *nn=new Node(curr->val);
			mp[curr]=nn;
			curr=curr->next;
		}
		
		curr=head;
		while(curr){
			cout << curr->val << "\n";
			 mp[curr]->next=mp[curr->next];
			mp[curr]->random=mp[curr->random];
			curr=curr->next;
		}
		return mp[head];
	}
	
};

int main(){
	Node *head=NULL;
	Solution A;
	head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(4);
	head->next->next->next->next=new Node(5);
	head->random=head->next->next->next; // 4
	head->next->random=head->next->next; // 3
	head->next->next->random=head; // 1
	head->next->next->next->random=head->next->next->next->next; //5
	head->next->next->next->next->random=head->next; // 2
	
	A.display(head);
	head=A.clone1(head);
	A.display(head);

	
}