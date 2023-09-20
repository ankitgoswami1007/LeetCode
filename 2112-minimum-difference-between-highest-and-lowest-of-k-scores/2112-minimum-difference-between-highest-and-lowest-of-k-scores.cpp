class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int  n = nums.size();
        if(n == 1 ) return 0;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i+k-1 < n ; i++){
            mn = min(mn, nums[i+k-1]-nums[i]);
        }
        return mn;
    }
};