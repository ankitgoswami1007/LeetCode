class Solution {


//     vector<string> split (const string &s, char delim) {
//     vector<string> result;
//     stringstream ss (s);
//     string item;

//     while (getline (ss, item, delim)) {
//         result.push_back (item);
//     }

//     return result;
// }
public:
    bool wordPattern(string pattern, string s) {
        //vector<string> word = split (s, ' ');

        unordered_map<char, int> umap1;
        unordered_map<string, int> umap2;

        istringstream in(s); string word;
        int n = pattern.size();
        int i = 0;

        for(word; in>>word ; i++ ){
            if(i == n || umap1[pattern[i]] != umap2[word]) return false;
            umap1[pattern[i]] = umap2[word] = i+1;
        }
        
        return i == n;
        //return umap1.size() == umap2.size();
    }
};