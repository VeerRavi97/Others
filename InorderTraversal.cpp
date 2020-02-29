#include<bits/stdc++.h>
using namespace std;
class TreeNode{
	public:
	TreeNode *left,*right;
	int val;
	TreeNode(int val){
		this->val=val;
		left=right=nullptr;
	}
};
class Solution
{
	 public:
	void inorder(TreeNode * root){
		if(!root) return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
		
	}
	void IterativeInorder(TreeNode * root){
		if(!root) return;
		stack<TreeNode*>s;
		TreeNode *current=root;
		while(!s.empty() || current){
			if(current) {
				s.push(current);
			current=current->left;
							  
			}
			else{
				current=s.top();
				s.pop();
				cout << current->val << " ";
				current=current->right;
			}
			
			
		}
		
		
		
	}
	
	
	
};
int main(){
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	Solution A;
	A.IterativeInorder(root);
	cout << "\n";
	
}