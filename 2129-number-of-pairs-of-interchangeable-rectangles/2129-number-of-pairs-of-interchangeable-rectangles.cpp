class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        unordered_map<double, long long> mp;

        for(int i = 0 ; i < rec.size(); i++){
            double ratio = rec[i][0]/(double)rec[i][1];
            mp[ratio]++ ;
        }
        long long res = 0 ;
        for(auto i : mp){
            long long val = i.second;
            if(val > 1){
                res += (val *(val-1)) /2.0;
            }
        }
        return res;
    }
};