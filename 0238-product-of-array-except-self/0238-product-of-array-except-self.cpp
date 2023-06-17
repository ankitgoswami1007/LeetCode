class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans;
        int pro = 1;
        int count = 0 ;
        for(auto& n : nums){
            if(n != 0) {
               pro *= n;
            } 
            if(n == 0){
                count++;
            } 
        }
        
        if(count > 1) {
            ans.resize(nums.size() , 0);
            return ans;
        }
        
        for(auto& n : nums){
            if(count){
                 int a = n ? 0 : pro;
                ans.push_back(a);
            }
            else
                ans.push_back(pro/n);
            
        }
       return ans ; 
    }
};