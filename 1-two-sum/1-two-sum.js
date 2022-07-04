/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let res = []
    let i = 0 ;
    let j = nums.length;
    let map = new Map();
    
    for( ;i < j ; i++){
        if(map.has(target-nums[i])){
            res.push(map.get(target- nums[i]));
            res.push(i);
            return res;
        }
        else
            map.set(nums[i], i);
            
    }
    
    
};