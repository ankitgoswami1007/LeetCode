class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.empty()) return "";
        
        unordered_map<char, int> mp;
        
        for(auto ch : t){
            mp[ch]++;
        }
        
        int count = 0, low = 0 , min_start, min_len = INT_MAX;
        
        for(int high = 0 ; high < s.size() ; high++){
            
            if(mp[s[high]] > 0 ) count++;
            
            mp[s[high]]--;
            
            if(count == t.length()){
                
                while(low < high && mp[s[low]] < 0){
                    mp[s[low]]++;
                    low++;
                }
                
                if(min_len > high-low+1){
                    min_start = low;
                    min_len = high-low+1;
                }
            }
        }
        
        if(min_len == INT_MAX) return "";
        
        return s.substr(min_start, min_len);
        
        
    }
};