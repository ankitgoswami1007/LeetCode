/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> numSet;
        
        for(auto& n : nums){
            if(numSet.find(n) != numSet.end()) return n;
            else numSet.insert(n);
        }
     return -1;
    }
}; */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i)
        ++m[nums[i]];
        
        for(auto i : m)
        {
            if(i.second > 1)
            {
                duplicate = i.first;
                break;
            }
        }
        return duplicate;
    }
	
};