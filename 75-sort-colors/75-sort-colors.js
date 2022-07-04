/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    
    let i = 0 , l = 0 , h = nums.length-1;
    
    while( i <= h){
        
        if(nums[i] == 0 ){
            // let temp = nums[i];
            // nums[i] = nums[l];
            // nums[l] = temp;
            [nums[i], nums[l]] = [nums[l], nums[i]];
            l++;
        }
        else if(nums[i] == 2){
            // let temp = nums[i];
            // nums[i] = nums[h];
            // nums[h] = temp;
            [nums[i], nums[h]] = [nums[h], nums[i]];
            h--;
            i--;
        }
        i++;
    }
    return ;
    
};