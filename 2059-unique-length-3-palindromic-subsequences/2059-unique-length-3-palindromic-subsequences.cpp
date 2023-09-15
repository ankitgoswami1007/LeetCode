struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);
 
        return h1 ^ h2;
    }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_set<int> left;
        std::unordered_set<std::pair<int, int>, pair_hash> res;
        unordered_map<int, int> right;

        for(int i = 0 ; i < s.size(); i++){
            right[s[i]]++;
        }

        for(int i = 0 ; i < s.size(); i++){
            right[s[i]] -= 1;
            if(right[s[i]] == 0){
                right.erase(s[i]);
            }
            for(int j = 0 ; j < 26 ; j++){
                char ch = j+'a';
                if(left.find(ch) != left.end() && right.find(ch) != right.end()){
                    res.insert({s[i], ch});
                }
            }
            left.insert(s[i]);
        }
        return res.size();
        
    }
};