class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int l1 = s.size();
        int l2 = s.size();
        if(l1 != l2) return false;

        unordered_map<char , char> mapST;
        unordered_map<char , char> mapTS;

        for(int i = 0 ; i < l1 ; i++){
            if((mapST.find(s[i]) != mapST.end() &&  mapST[s[i]] != t[i]) || (mapTS.find(t[i]) != mapTS.end() &&  mapTS[t[i]] != s[i]) )
                return false;
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        return true;
    }
};