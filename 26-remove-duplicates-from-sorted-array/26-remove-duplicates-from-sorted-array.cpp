class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0 ;
        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        //for(int k = 0 ; k < i+1 ; k++) cout<<nums[k]<<" " ;
        return i+1;     
    }
};