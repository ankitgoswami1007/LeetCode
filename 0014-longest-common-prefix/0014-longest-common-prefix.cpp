class Solution {
    string helper(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        int i = 0, j = 0;
        string res = "";

        while(i < l1 && j < l2){
            if(s1[i] == s2[j]){
                if(i == j) res += s1[i];
                i++;
            }
            j++;
        }
        s1 = res;
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string res = "";

        string first = strs[0];

        for(int i = 1 ; i < strs.size() ; i++){
            res = helper(first, strs[i]);
            first = res;
        }
        return res;
    }
};