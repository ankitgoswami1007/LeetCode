class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;  // Result vector to store the triplets
        if(nums.size() < 3) return res;  // If there are less than 3 elements, return empty result
        
        sort(nums.begin(), nums.end());  // Sort the input array in ascending order
        
        for(int i = 0; i < nums.size()-2; i++) {
            // Skip duplicate values for the first element of the triplet
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i + 1, high = nums.size() - 1, sum = 0 - nums[i];  // Set pointers for the remaining two elements
                
                while (low < high) {
                    if(nums[low] + nums[high] == sum) {
                        vector<int> a;
                        a.push_back(nums[i]);
                        a.push_back(nums[low]);
                        a.push_back(nums[high]);
                        res.push_back(a);  // Found a valid triplet, add it to the result
                        
                        // Skip duplicate values for the remaining two elements
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum) {
                        low++;  // Move the low pointer to increase the sum
                    }
                    else {
                        high--;  // Move the high pointer to decrease the sum
                    }
                }
            } 
        }
        
        return res;  // Return the result vector
    }
};


/* 
*The time complexity of this code is O(n^2), where n is the number of elements in the input array nums.

The initial sorting operation takes O(n log n) time complexity.
The outer loop iterates over each element of nums, which takes O(n) time.
Within the outer loop, the inner while loop performs a two-pointer approach, which takes O(n) time in the worst case scenario.
Overall, the time complexity is dominated by the sorting operation, resulting in O(n log n).
*/
