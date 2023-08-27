class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> umap;
        int l = nums.size();
        int ans = -1;
        for(auto num : nums){
            umap[num]++;
            if(umap[num] > l/2) {
                    ans = num ; break;
            }
        }
        return ans;
    }
};