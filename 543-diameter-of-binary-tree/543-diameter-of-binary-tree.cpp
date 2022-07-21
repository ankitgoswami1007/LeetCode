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
    int diameter(TreeNode* root , int &ans){
        if(root ==  NULL) return 0;
        int lh = diameter(root->left , ans);
        int rh = diameter( root -> right , ans);

        ans = max(ans , lh+rh);
        return max(lh , rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN ;
        if(root ==  NULL) return 0;
        diameter(root , ans);
        return ans ;
        
    }
};