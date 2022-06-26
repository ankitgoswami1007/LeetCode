class Solution { 
  
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return intervals;
        
        vector< vector<int>> res ;
      /*  sort(intervals.begin() , intervals.end());
        
        stack <vector<int>> s;
        s.push(intervals[0]);
        
        for(int i = 1 ; i < n ; i++){
            
            vector<int> top = s.top();
            
            if(top[1] < intervals[i][0]){
                s.push(intervals[i]);
            }
            else if(top[1] < intervals[i][1]){
                top[1] = intervals[i][1];
                s.pop();
                s.push(top);
            }
        }
        
        while(!s.empty()){
            vector<int> top = s.top();
            res.push_back(top);
            s.pop();
        }
        sort(res.begin(), res.end()); */
        sort(intervals.begin() , intervals.end());
        res.push_back(intervals[0]);
        
        for (int i = 1 ; i < n ; i++){
            
            if(res.back()[1] >= intervals[i][0]) res.back()[1] = max(res.back()[1], intervals[i][1]);
            else res.push_back(intervals[i]);
        }
     return res;    
        
    } 
};