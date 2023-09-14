class Solution {
    
     
    int helper(vector<int>& prices ,int index, int buy){
        if(index == prices.size()) return 0;
        
        int profit = 0;
        if(buy){
            profit = max( -prices[index] + helper(prices, index+1 , 0)
                         , 0 + helper(prices, index+1 , 1));
        }
        else{
             profit = max( prices[index] + helper(prices, index+1 , 1)
                          , 0 + helper(prices, index+1 , 0));
        }
    return profit;
    }
    
    int helper2(vector<int>& prices ,int index, int buy, vector<vector<int>>& dp){
        if(index == prices.size()) return 0;
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        int profit = 0;
        if(buy){
            profit = max( -prices[index] + helper2(prices, index+1 , 0, dp)
                         , 0 + helper2(prices, index+1 , 1, dp));
        }
        else{
             profit = max( prices[index] + helper2(prices, index+1 , 1, dp)
                          , 0 + helper2(prices, index+1 , 0, dp));
        }
    return dp[index][buy] =  profit;
    }
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        if(prices.size() == 0) return -1 ; 
        int maxProfit = 0 ; 
       // method 1 ----> most efficient
        
        for(size_t i = 1 ; i < prices.size() ; i++){
                
            if(prices[i] > prices[i-1]){
               maxProfit += (prices[i] - prices[i-1]);
            }
        } 
        return maxProfit ; 
        
        // method 2 ----> using recusion
        //return helper(prices , 0 , 1);
        
        // method 3 ----> using memoization
       /* vector<vector<int>> dp(n, vector<int> (2, -1)); 
        return helper2(prices , 0 , 1 , dp); */
         
        // method 4 using 4 variable
       /* int aheadBuy , aheadNotBuy, curBuy, curNotBuy ;
        aheadBuy = aheadNotBuy = 0 ;
        
        for(int index = n-1 ;  index >= 0 ; index--){
            
            curNotBuy = max( prices[index] + aheadBuy
                          , 0 +  aheadNotBuy);
            
            curBuy = max( -prices[index] + aheadNotBuy
                         , 0 + aheadBuy );
            
            aheadBuy =  curBuy;
            aheadNotBuy =  curNotBuy;
	    }
	    return aheadBuy; */

    }
};