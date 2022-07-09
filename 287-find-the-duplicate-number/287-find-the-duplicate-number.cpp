class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> numSet;
        
        for(auto& n : nums){
            if(numSet.find(n) != numSet.end()) return n;
            else numSet.insert(n);
        }
     return -1;
    }
};