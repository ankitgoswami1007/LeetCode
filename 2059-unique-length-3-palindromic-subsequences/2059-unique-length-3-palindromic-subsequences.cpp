class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26);
        vector<int> right(26);
        unordered_set<string> st;

        for(auto ch : s){
            right[ch-'a']++;
        }

        for(int i = 0 ; i < s.size() ; i++){
            right[s[i]-'a']--;
            for(int j = 0 ; j < 26 ; j++){
                if(left[j] > 0 && right[j]> 0){
                    char ch = j + 'a';
                    string res = "";
                    res += ch; res += s[i]; res += ch;
                    
                    if(st.count(res)) continue;
                    st.insert(res);
                }
            }
            left[s[i]-'a']++;
        }
        return st.size();
    }
};