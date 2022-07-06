/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    /*for(let i = 0 ; i < nums.length-1 ; i++ ) {
        for(let j = i+1 ; j < nums.length ; j++){
            if(nums[i] + nums[j] == target) return [i , j];
        }
    }
    return -1; */
    
    let map = new Map();
    let res = [];
    for(let i = 0 ; i < nums.length ; i++){
        
        if(map.has(target-nums[i])){
            res.push(map.get(target-nums[i]));
            res.push(i);
            return res;
        }
        else{
            map.set(nums[i], i);
        }
    }
    
    
};