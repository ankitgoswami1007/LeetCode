class Solution {
    
   unordered_map<int , vector<int>> umap;
    int ans = 0 , mx = 0 ;
    // source = manager
    void  dfs( int manager, vector<int>& informTime) {
        mx = max(ans, mx);
        
        for(auto employee: umap[manager]){
            ans += informTime[manager];
            
            dfs(employee, informTime);
            
            ans -= informTime[manager];
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
      
        
        for(int i = 0 ; i < n ; i++){
            if(manager[i] == -1) continue;
            int val = manager[i];
            umap[val].push_back(i);
        }
        
        dfs(headID, informTime);
        return mx;
    }
};