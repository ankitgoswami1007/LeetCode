class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > missing) break;
            else if(nums[i] == missing) missing++;
        }
        return missing;
    }
};