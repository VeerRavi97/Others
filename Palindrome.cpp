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
	
	 void split(Node *head,Node ** aref, Node **bref){
		 Node *fast=head;
		 Node *slow=head;
		 Node *pre=NULL;
		 while(fast && fast->next){
			 pre=slow;
			 slow=slow->next;
			 fast=fast->next->next;
		 }
		 if(!fast) slow=pre;
		 *bref=slow->next;
		 pre->next=NULL;
		 *aref=head;
		 return;
	 }
	Node *reverse(Node *head){
		if(!head || !head->next) return head;
		Node *curr=head;
		Node *pre=NULL;
		while(curr){
			Node *next=curr->next;
			curr->next=pre;
			pre=curr;
			curr=next;
		}
		return pre;
	}
	
	bool CompareLists(Node *a, Node *b){
		if(!a && !b) return true;
		if(a && !b) return false;
		if(!a && b) return false;
		if(a->val==b->val)
			return CompareLists(a->next,b->next);
		return false;
		
	}
	
	
	bool CheckPalindrome(Node *head){
		
		if(!head || !head->next) return true;
		Node *a=NULL;
		Node *b=NULL;
		split(head,&a,&b);
		a=reverse(a);
		display(a);
		display(b);
		
		return CompareLists(a,b);
		
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
	bool ans=A.CheckPalindrome(head);
	// A.display(head);
	cout << ans << "\n";

	
}