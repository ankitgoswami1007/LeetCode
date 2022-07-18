/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findInorderTraversalHelper(TreeNode* root , vector<int>& ans){
		if(root == NULL) return ;
		findInorderTraversalHelper(root->left , ans);
		ans.push_back(root->val);
		findInorderTraversalHelper(root->right , ans );
	}
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s ;
		vector<int> ans ;
	    TreeNode* temp = root;
		
		while (temp != NULL || !s.empty()){
			
			if(temp != NULL){
				s.push(temp);
				temp = temp->left;
			}
			else{
				temp = s.top();
				s.pop();
				ans.push_back(temp->val);
				temp = temp->right;
			}
		} 
    
		//findInorderTraversalHelper( root , ans);
		return ans;
		
	}
        
    
};