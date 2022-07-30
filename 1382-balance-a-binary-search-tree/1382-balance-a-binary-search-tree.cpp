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
    vector<int> in;
public:
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        
        inOrder(root->left);
        in.push_back(root->val);
        inOrder(root->right);
    }
    
    TreeNode* inorderToBBST(int s , int e ){
        if(s > e) return NULL;
        
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = inorderToBBST(s, mid-1);
        root->right = inorderToBBST(mid+1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        inOrder(root);
        
        return inorderToBBST(0 , in.size()-1);
    }
};