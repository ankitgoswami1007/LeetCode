class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        /*int i = 0 ;
        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        } */
        int count = 1;
        int i = 0 ;
        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[i] == nums[j]){
                count++; 
                if(count > 2) continue ;    
            }
            else{
                count = 1;
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;     
    }
};