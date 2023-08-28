class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size(), sum1 = 0, sum2 = 0;
        for(auto& num : nums){
            sum1 += num;
        }
        
         for(int i = 0 ; i < n ; i++){
             sum1 -= nums[i];
             if(sum2 == sum1) return i;
             sum2 += nums[i];
         }
        
        return -1;
        
    }
};