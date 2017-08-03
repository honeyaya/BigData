#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
};

TreeNode * CreateBitTree(){
	int data;
	scanf("%d",&data);
	if(data == 0) 
		return NULL;
	else{
		TreeNode *tmp = new TreeNode();
		tmp->val = data;
		tmp->left = CreateBitTree();
		tmp->right = CreateBitTree();
		return tmp;
	}
}

int countNode(TreeNode * root){
	if(!root) return 0;
	return countNode(root->left) + countNode(root->right) + 1;
}

int getDepth(TreeNode * root){
	if(!root) return 0;
	return max(getDepth(root->left),getDepth(root->right)) + 1;
}

void preorder(TreeNode * root){
	if(root != NULL){
		cout << root->val << " ";
		
		preorder(root->left);
		preorder(root->right);
	}		
}

void print(vector<int> vc){
	int len = vc.size();
	for(int i = 0; i < len; i++)
		cout << vc[i] << " ";
	cout << endl;
	return ;
}

void levelTraverse(TreeNode * root){
	
}
int main(){
	int n;
	TreeNode *  bt = CreateBitTree();
	//cout << "----" << endl;
	//preorder(bt);
	//int nodecnt = countNode(bt);
	//int depth = getDepth(bt);
	
	
	return 0;
}

/*

1 2 4 0 0 5 0 0 3 6 0 0 0

*/
