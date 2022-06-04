class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return -1 ; 
        int maxProfit = 0 ; 
       
        for(size_t i = 1 ; i < prices.size() ; i++){
                
            if(prices[i] > prices[i-1]){
               maxProfit += (prices[i] - prices[i-1]);
            }
        } 
        return maxProfit ;
    }
};