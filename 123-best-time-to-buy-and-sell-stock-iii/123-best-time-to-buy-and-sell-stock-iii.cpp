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
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector< vector<vector<int>>> dp( n, vector<vector<int>>(2, vector<int> (3 , -1 ))) ;
        //return helper(prices , 0 , 1 , 2 , dp);
        
        int buy1 = INT_MAX;
        int profit1 = INT_MIN;
        int buy2 = INT_MAX;
        int profit2 = INT_MIN;
        
        for(auto& p : prices){
            buy1 = min(buy1, p);
            profit1 = max(profit1 , p-buy1);
            buy2 = min(buy2, p-profit1);
            profit2 = max(profit2, p-buy2);
            
        }
        return profit2;
    }
};