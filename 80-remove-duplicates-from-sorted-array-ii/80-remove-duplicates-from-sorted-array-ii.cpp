class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
       /* int count = 1 , k = 1 ;
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                count++ ;
                if(count > 2) continue ;
            } 
            
            else{
                count = 1 ;
            }
            nums[k++] = nums[i];
        }
       
        return k ; */
        
        int indx = 2 ;
        for(int i = 2 ; i < n ; i++){
            if(nums[i] != nums[indx-2]){
                nums[indx] = nums[i];
                indx++;
            }
        }
        return indx;
    }
};