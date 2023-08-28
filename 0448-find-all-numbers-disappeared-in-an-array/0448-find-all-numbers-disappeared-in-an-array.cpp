class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();

        unordered_set<int> ust;
        for(int i = 1 ; i <= n ; i++){
            ust.insert(i);
        }

        for(auto& ele : nums){
            if(ust.find(ele) != ust.end()){
                ust.erase(ele);
            }
        }
        for(auto ele : ust) {
            ans.push_back(ele);
        } 
        return ans;
    }
};