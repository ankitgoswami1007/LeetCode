/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
        let ans = [];
        let pro = 1;
        let count = 0 ;
        for(const n of nums){
            if(n != 0) {
               pro *= n;
            } 
            if(n == 0){
                count++;
            } 
        }
        
        if(count > 1) {
            ans1 = Array(nums.length).fill(0);
            return ans1;
        }
        
        for(const n of nums){
            if(count){
                 let a = n ? 0 : pro;
                ans.push(a);
            }
            else
                ans.push(pro/n);
            
        }
       return ans ; 
    
}