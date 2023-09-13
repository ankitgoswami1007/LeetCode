class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> umap;
         int res = 0;
        int n = wall.size();
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            for(int j = 0 ; j < wall[i].size()-1 ; j++){
                count += wall[i][j];
                umap[count]++;
                res = max(res, umap[count]);

            }
        }
       return n-res;
    }
};