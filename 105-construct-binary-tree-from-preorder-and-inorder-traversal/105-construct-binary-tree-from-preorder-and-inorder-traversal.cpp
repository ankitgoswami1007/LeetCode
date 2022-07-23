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
    
    int search(vector<int>& in,int is, int ie ,int x)
    {
        for(int i=is ; i<= ie ; i++)
        {
            if(in[i]==x) return i;
        }
        return -1;
    }
    int i = 0 ;
public:
   /* TreeNode* helper(vector<int>& preorder , int ps , int pe , vector<int>& inorder , int is , int ie ){
        
        if(ps > pe) return NULL ;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        
        int index = search(inorder , is , ie , preorder[ps]);
        int i = index - is;
        
        root->left = helper( preorder , ps+1 , ps+i , inorder, is , index-1 );
        
        root->right = helper(preorder , ps+i+1 , pe , inorder, index+1 , ie );
        
        return root ;
    }  */
    
    TreeNode* helper(vector<int>& preorder ,vector<int>& inorder, int s , int e )
    {
        
        if(s > e) return NULL ;
        
        int data = preorder[i];
        i++;
        
        TreeNode* root = new TreeNode(data);
        int k = -1;
        
        for(int j = s ; j <= e ; j++ ){
            if (inorder[j] == data) {
                k = j;
                break;
            }
        }
        root->left = helper(preorder , inorder, s , k-1 );
        root->right = helper(preorder , inorder, k+1 , e );
        
        return root ;
        
    } 
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        int m = inorder.size();
        
        if(m == 0 || n == 0) return NULL ;
        
       
        
        TreeNode* root = helper(preorder , inorder, 0 , m-1 );
         //TreeNode* root = helper(preorder ,0 , n-1 , inorder, 0 , m-1 );
        return root ;
    }
};