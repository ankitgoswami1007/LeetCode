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
    vector<int> postorderTraversal(TreeNode* root) {
        
        
        vector<int> ans ;
        if (root == NULL) return ans ;
        
        stack <TreeNode*> s;
        stack <int> si;
        s.push(root);
        TreeNode* temp ;
        
        while(!s.empty()){
            
            temp = s.top();
            s.pop();
            //si.push(temp->val);
            ans.push_back(temp->val);
            
            if(temp-> left)
                s.push(temp->left);
            
            if(temp->right)
                s.push(temp->right);
        }
     
       // while(!si.empty()){
       //     ans.push_back(si.top());
       //     si.pop();
       // } 
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};