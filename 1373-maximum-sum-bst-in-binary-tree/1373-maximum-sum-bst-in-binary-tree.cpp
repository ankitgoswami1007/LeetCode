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
class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
        int maxSum;
    
};
class Solution {
    int sum = 0 ;
public:
    info solve(TreeNode* root , int &ans){
        
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0, 0};
        }
        
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        info curNode;
        
        curNode.maxi = max(root->val, right.maxi);
        curNode.mini = min(root->val, left.mini);
        
        curNode.size = left.size + right.size + 1;
        
        if(left.isBST == true && right.isBST == true && ( root->val > left.maxi  && root->val < right.mini) ){
            curNode.isBST = true;
            curNode.maxSum = left.maxSum + right.maxSum + root->val;
        }
        else{
            curNode.isBST = false;
            curNode.maxSum = max(left.maxSum , right.maxSum );
        }
        
        if(curNode.isBST){
            ans = max(ans, curNode.size);
        }
        sum = max(sum, curNode.maxSum);
        return curNode;
    }
    
    int maxSumBST(TreeNode* root) {
        int maxSize = 0 ;
        info temp = solve(root , maxSize);
        return sum;
    }
};