class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n = nums.size(), curSum = 0;
        
        for(int i = 0 ; i < n ; i++ ){
            curSum += nums[i];
            prefixSum.push_back(curSum);
        }
    }
    
    int sumRange(int left, int right) {

        int ans = 0 ;
        if(left > 0) ans = prefixSum[right] - prefixSum[left-1];
        else ans = prefixSum[right];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */