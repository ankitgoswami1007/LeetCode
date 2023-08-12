class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans = nums;
        for(auto ele : nums){
            ans.push_back(ele);
        }
        return ans;
    }
};