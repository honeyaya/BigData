/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int ans,nth;
public:
	void inorder(TreeNode* root, int k){
		if(root->left)
			inorder(root->left);
		nth++;
		cout << root->val <<" ";
		if(nth == k) 
			ans = root->val;
		if(root->right)
			inorder(root->right); 	
	}
	
    int kthSmallest(TreeNode* root, int k) {
  		
		// Inorder
		nth = 0;
		inorder(root, k);
		return ans;   
    }
};



