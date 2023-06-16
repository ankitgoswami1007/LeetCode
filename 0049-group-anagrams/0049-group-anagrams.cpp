class Solution {
    string getKey(string str){
        vector<int> count(26);

        for(int i = 0 ; i < str.size() ; i++){
            count[str[i] - 'a']++;
        }

        string key = "";

        for(int i = 0 ; i < 26 ; i++){
            
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(int i = 0 ; i < strs.size() ; i++){
            string key = getKey(strs[i]);
            um[key].push_back(strs[i]);
        }

        vector<vector<string>> res;
        // for(auto it = um.begin(); it != um.end(); it++){
        //     res.push_back(it->second);
        // }

        for(auto &it : um){
            res.push_back(it.second);
        }



        return res;
    }
};