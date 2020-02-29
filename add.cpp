#include<bits/stdc++.h>
using namespace std;
int carry=0;
class Node{
	public:
	int val;
	Node *next;	
	Node(int val){
		this->val=val;
		this->next=NULL;
	}
};
// hello
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
	Node *add(Node *head1, Node *head2){
		if(!head1 && !head2) return nullptr;
		Node *result=new Node(0);
		result->next=add(head1->next,head2->next);
		int sum=head1->val+head2->val+carry;
		//cout << "Adding " << head1->val << " " << head2->val << " " << sum << "\n";

		if(sum>9) carry=1;
		else carry=0;
		sum%=10;
		result->val=sum;
		return result;
	}
	Node *addRemaining(Node *head1){
		if(!head1) return nullptr;
		Node * copy=new Node(0);
		copy->next=addRemaining(head1->next);
		int sum=head1->val+carry;
		if(sum>9) carry=1;
		else carry=0;
		sum%=10;
		copy->val=sum;
		return copy;
	}
	
	Node *addLists(Node *head1, Node *head2,int n,int m){
		if(!head1 && !head2) return nullptr;
		if(!head1 && head2) return head2;
		if(!head2 && head1) return head1;
		if(m>n) swap(head1,head2);
		int diff=abs(n-m);
		Node *miniHead=head1;
		Node *pre=NULL;
		for(int i=1;i<=diff;i++){
			pre=miniHead;
			miniHead=miniHead->next;
		}
		if(pre) pre->next=NULL;
	  // display(head1);
	  // display(miniHead);
	  // display(head2);
	   Node *miniresult=add(miniHead,head2);
	  Node*result=miniresult;
		if(diff){
	      result=addRemaining(head1);
		  Node *last=result;
		  while(last->next){
			  last=last->next;
		  }	
		 last->next=miniresult;
		}
	  if(carry){
		  Node *one=new Node(1);
		  one->next=result;
		  result=one;
	  }
	  //display(miniresult);
	   return result;
			
	}

	
};

int main(){
	int n,m;
	cin >> n >> m;
	Node *head1=NULL;
    Node *head2=NULL;
	Solution A;
	for(int i=0;i<n;i++){
		int in;
		cin >> in;
		head1=A.insert(head1,in);
		
	}
	 for(int i=0;i<m;i++){
		int in;
		cin >> in;
		head2=A.insert(head2,in);
		
	}

	//A.display(head);
	Node *result=NULL;
	result=A.addLists(head1,head2,n,m);
	A.display(result);

	
}