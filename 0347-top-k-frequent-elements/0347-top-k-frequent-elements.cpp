class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         int n = nums.size();
         unordered_map<int, int> mp;
         vector<int> res;
       
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

       /* priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(auto & it : mp) {
            pq.push({it.second, it.first});

            if(pq.size() > k) pq.pop();
        }

         while(!pq.empty()){
             res.push_back(pq.top().second);
             pq.pop();
         } */

         vector<vector<int>> buckets(n + 1);

         for(auto & it : mp) {
             buckets[it.second].push_back(it.first);
         }

         for(int i = n ; i >= 0 ; i--){
             if(res.size() >= k) {
                 break;
             }
             if(!buckets[i].empty()){
                 res.insert(res.end(), buckets[i].begin(), buckets[i].end());
             }
         }
        return res;
    }
};