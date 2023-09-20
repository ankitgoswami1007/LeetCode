class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int  n = nums.size();
        int j = k-1, i = 0;
        sort(nums.begin(), nums.end());

        while(j < n) {
            mn = min(mn, nums[j++]- nums[i++]);
        }
        return mn;
    }
};