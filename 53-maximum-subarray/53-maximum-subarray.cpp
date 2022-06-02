class Solution {
public:
     int maxSubArray(vector<int>& nums) {
      int cur_sum = nums[0];
        int max_sum = nums[0] ;
        
        for(int i = 1 ; i < nums.size() ; i++){
            cur_sum = max(nums[i] , cur_sum+nums[i]);
            max_sum = max(max_sum , cur_sum);
        }
        return max_sum;
      
    
    
   /* int sum = 0 , final_sum = INT_MIN;
  
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        
        final_sum = max(final_sum , sum);
        if(sum < 0) sum = 0;
    }
    return final_sum;*/
    }      
};