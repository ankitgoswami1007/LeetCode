class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        int i = 0 ;
        int j = nums.size();
        unordered_map<int, int> umap;
       
        for (int i = 0 ;  ; i++){
            if(umap.count(target - nums[i])){
                return {i , umap[target-nums[i]]};
            }
            else
            umap[nums[i]] = i ;
        }
        
      
       return res ; 
    }
};