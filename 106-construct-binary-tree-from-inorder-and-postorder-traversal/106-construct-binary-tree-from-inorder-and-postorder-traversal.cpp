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
    map<int, int> nodeToIndex;
     
    void createMapping(vector<int> inorder, int n) {
        for(int i = 0 ; i < n ; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* create(vector<int>& inorder, vector<int>& postorder ,int s , int e , int &i){
    
    if(s > e) return NULL;
    
    int data = postorder[i];
        i = i-1;
    TreeNode* root = new TreeNode(data);
    
    int k = -1;
    k = nodeToIndex[data];
    // for(int j = s ; j <= e ; j++){
    //     if(inorder[j] == data){
    //         k = j;
    //         break;
    //     }
    // }
        root->right = create(inorder , postorder , k+1 , e , i);
        root->left = create(inorder , postorder , s , k-1 , i);
        
        return root ;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        int sz = n-1;
        if(n == 0 ) return NULL;
        
        createMapping(inorder, n);
        
        TreeNode* root ;
        
        root = create( inorder,  postorder , 0 , n-1 , sz);
        
        //------------------ approach 2 --------------------------
       /* stack <TreeNode*> st;
        TreeNode* t;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        st.push(root);
        
        while(true){
            
            if(st.top()->val == inorder.back()){
                
                t = st.top();
                st.pop();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(st.size() && st.top()->val == inorder.back() ) continue;
                t->left = new TreeNode(postorder.back());
                postorder.pop_back();
                st.push(t->left);
                
            }
            else{    
            t = new TreeNode(postorder.back());
            postorder.pop_back();
            st.top()->right = t;
            st.push(t);
            }
        } */
        return root ;
    }
};