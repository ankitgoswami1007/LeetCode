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
    int i = 0 , preIndex = 0 , postIndex = 0  ;
    map<int, int> nodeToIndex;
    
    void createMapping(vector<int> postorder, int n) {
        for(int i = 0 ; i < n ; i++){
            nodeToIndex[postorder[i]] = i;
        }
    }
    
    TreeNode* create( vector<int>& preorder, int ps, int pe, vector<int>& postorder , int pps , int ppe ){
        
        if(i >= preorder.size() || ps > pe) return NULL ;
        
        int data = preorder[i];
        TreeNode* root = new TreeNode(data);
        i++ ;
        if(ps == pe) return root ;
    
        
        // int index = pps;
        // while(postorder[index] != preorder[ps+1]) index++;
        int index = nodeToIndex[preorder[ps+1]];
        
        int tnel = index-pps+1;
        
        root->left = create(preorder ,ps+1, ps+tnel, postorder , pps , index);
        root->right = create(preorder , ps+tnel+1, pe , postorder , index+1  , ppe -1);
       
        
        return root ; 
    } 
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
         int n = preorder.size();
        
        if( n == 0 ) return NULL;
        
        
        TreeNode* root ;
        
        createMapping(postorder, n);
        
        root = create(preorder, 0, n-1, postorder , 0 , n-1);
        
        return root ; 
      /*  TreeNode * root = new TreeNode(preorder[preIndex++]);
        
        if(root->val != postorder[postIndex])
            root->left = constructFromPrePost(preorder , postorder);
        
        if(root->val != postorder[postIndex])
            root->right = constructFromPrePost(preorder , postorder);
        
        postIndex++; 
        return root; */
    }
};