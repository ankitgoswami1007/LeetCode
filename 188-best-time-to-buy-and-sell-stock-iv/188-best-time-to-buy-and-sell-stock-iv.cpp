class Solution {
    
     int helper(vector<int>& prices , int indx , int buy , int cap, vector< vector<vector<int>>>& dp){
        if(indx == prices.size() || cap == 0) return 0;
        
        if(dp[indx][buy][cap] != -1) return dp[indx][buy][cap];
        int profit = 0;
        if(buy){
           profit = max( -prices[indx] + helper(prices , indx+1 , 0 , cap, dp), 0 + helper(prices , indx+1 , 1 , cap, dp)) ;
        }
        else {
             profit = max( prices[indx] + helper(prices , indx+1 , 1 , cap-1, dp), 0 + helper(prices , indx+1 , 0 , cap, dp)) ;
        }
        
        return  dp[indx][buy][cap] = profit ;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ;
        vector< vector<vector<int>>> dp( n, vector<vector<int>>(2, vector<int> (k+1 , -1 ))) ;
        return helper(prices , 0 , 1 , k , dp);
    }
};