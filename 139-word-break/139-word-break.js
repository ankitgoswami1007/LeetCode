/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    
    if(wordDict.length == 0) return false ;
    
    let n = s.length;
    
    let dp = new Array(n+1).fill(false);
    dp[n] = true ;
    
    for(let i = n-1 ; i >= 0 ; i--){
        
        for(const word of wordDict){
            
            if( (i+ word.length <= n) && s.substring(i , i+word.length) == word){
                dp[i] = dp[i+ word.length] ;
            }
            if(dp[i] == true) break ;
        }
    }
    return dp[0];
};