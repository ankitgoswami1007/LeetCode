class Solution {
    bool isPalindrome(string &s) {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
public:
    int maxProduct(string s) {
        int n = 1 << s.length();
        vector<pair<int, int>> Map;
        for(int i = 0; i < n; i++) {
            string seq = "";
            for(int j = 0; j < s.length(); j++) {
                if((i >> j) & 1) {
                    seq += s[j];
                }
            }
            if(isPalindrome(seq)) Map.push_back({i, seq.length()});
        }
        int ans = 0;
        for(int i = 0; i < Map.size(); i++) {
            for(int j = i + 1; j < Map.size(); j++) {
                if((Map[i].first & Map[j].first) == 0) {
                    ans = max(Map[i].second * Map[j].second, ans);
                }
            }
        }
        return ans;
    }
};