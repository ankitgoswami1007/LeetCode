class TreeAncestor {
    vector<vector<int>> table ;
    //static int row = 17;
public:
    TreeAncestor(int n, vector<int>& parent) {
       // for(int i = 0 ; i < n ; i++)    dummy.push_back(parent[i]);
        
        table.resize(17 , vector<int>(parent.size(), -1));
        
        for(int i = 0 ; i < n ; i++) table[0][i] = parent[i];
        
        for(int i = 1 ; i < 17 ; i++){
            for(int node = 0 ; node < parent.size() ; node++){
                
                int parentNode = table[i-1][node];
                if(parentNode != -1) table[i][node] = table[i-1][parentNode];
            }
        }
        
        
         
    }
    
    int getKthAncestor(int node, int k) {
       /* int n = dummy.size();
        
        if(n == 0) return node;
        int index = -1;
        int end = n-1 , start = 0;
        for( int i = n-1 ; i >= 0 ; i--){
            
            if(i == node){ 
            index  = i ;
              while(k--) {
                  index = dummy[index];
                  if(index == -1) return -1;
              } 
              break ; 
            }
        }
        if( index < 0) return -1;
        return index; */
        
        for(int i = 0 ; i < 17 ; i++){
            
            int mask = (1<<i);
            if((k&mask) > 0) 
            {
                node = table[i][node];
                if(node == -1) return -1;
            }
        }
        return node ;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */