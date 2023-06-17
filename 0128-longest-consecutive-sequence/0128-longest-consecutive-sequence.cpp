class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> umap;

        for(auto & num : nums){
            umap[num] = true;
        }

        for(auto & num : nums){
            if(umap.find(num -1) != umap.end()) umap[num] = false;
        }

        int max_start_point = 0;
        int max_len = 0;
        for(auto & num : nums){
            if(umap[num] == true) {
                int temp_len = 1;
                int temp_start_pnt = num;

                while(umap.find(temp_start_pnt + temp_len) != umap.end()){
                    temp_len++;
                }
                if(temp_len > max_len) {
                    max_len = temp_len;
                    max_start_point = temp_start_pnt;
                }
            }
        }
        for(int i = 0 ; i < max_len ; i++){
            cout<<(max_start_point+i)<<" ";
        }
        return max_len;
    }
};