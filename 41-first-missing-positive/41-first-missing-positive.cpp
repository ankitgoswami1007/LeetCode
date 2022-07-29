class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
       /* sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > missing) break;
            else if(nums[i] == missing) missing++;
        }
        return missing; */
        
        //---------------2nd approach
        
       /* set<int> set;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= 0) continue;
            set.insert(nums[i]);
        }
        for(int i = 1 ; i < n+1 ; i++){
            if(set.find(i) == set.end()) return i ;
        }
        return n+1;  */
        
         //---------------2nd approach
        
        unordered_set<int> set;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= 0) continue;
            set.insert(nums[i]);
        }
        for(int i = 1 ; i < n+1 ; i++){
            if(set.find(i) == set.end()) return i ;
        }
        return n+1; 
    }
    
};