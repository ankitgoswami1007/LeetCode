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
  /*  void preorderTraversalHelper(TreeNode* root , vector<int>& ans){
        
        if(root == 0 ) return ;
        ans.push_back(root->val);
        preorderTraversalHelper(root->left , ans);   
        preorderTraversalHelper(root->right , ans);


    }*/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans ;
        if (!root) return ans ;
    
       // preorderTraversalHelper(root , ans);
        stack<TreeNode*> s;
        s.push( root );
        TreeNode* temp ;
        
        while(!s.empty() ){
           temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            
            if(temp->right)
                s.push(temp->right);
            
            if(temp->left)
                s.push(temp->left);
           
        }
        return ans;
        
    }
    
};