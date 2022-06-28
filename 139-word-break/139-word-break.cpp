class Solution {
   // unordered_set<string> dset;
   // unordered_map<int,bool> mp;
   /* bool helper(string s , int pos){
        
        if(pos == s.size()) return true;
        if(mp.count(pos)) return mp[pos];
        
        for(int i = pos ; i < s.size() ; i++){
            
            if(dset.count(s.substr(pos , i-pos+1)) && helper(s, i+1))
                return mp[pos] = true ;
        }
        return mp[pos] = false ;
    } */
    
    bool helper2(string s , int n , vector<string>& wordDict, int m){
        vector<bool> dp(n+1 , false);
        
        dp[n] = true;
        int s_len = n ;
        for(int i = n-1 ; i >= 0 ; i--){
            
            for(auto word : wordDict){
                int len_word = word.size();
                
                if((i+ len_word)<= s_len && s.substr(i , len_word) == word){
                    //cout<<s.substr(i , len_word) <<"==" << word<< endl;
                    //apple==apple
                    //pen==pen
                    //apple==apple
                    
                    dp[i] = dp[i + len_word];
                    //cout<<dp[i] <<"--"<<i<<"--" <<dp[i + len_word] <<"--"<<(i+len_word)<<endl;
                   // 1--8--1--13
                   // 1--5--1--8
                   // 1--0--1--5
                }
                if(dp[i] == true) break;
            }
        }
        return dp[0];
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0 ) return false;
      /* for(auto st : wordDict){
            dset.insert(st);
        }
        return helper(s , 0); */
        return helper2(s , s.size() ,wordDict ,wordDict.size());
    }
};