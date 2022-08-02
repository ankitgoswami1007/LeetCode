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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        
        while(cur != NULL){
            
            if(cur->left != NULL){
                
                TreeNode* pred = cur->left;
                
                while(pred->right != NULL){
                    pred = pred->right;
                }
                pred->right = cur->right;
                cur->right = cur->left;
            }
            cur = cur->right;
        }
        cur = root;
          while(cur != NULL){
            cur->left = NULL;
            cur = cur->right;
        }
        
    }
};