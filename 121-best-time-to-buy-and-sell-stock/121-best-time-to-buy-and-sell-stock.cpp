class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyStock = INT_MAX;
        int sellStock = INT_MIN;
        int res = 0;
        for(auto& p : prices){
            buyStock =min(buyStock , p);
            sellStock = max(sellStock , p-buyStock);
            
        }
        if(sellStock > 0) res = sellStock ;
        return  res ;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& arr) {
        
//         int ans = 0;
//         int minprice = INT_MAX;
        
//         for(int i = 0 ; i < arr.size() ; i++){
//             minprice = min(minprice, arr[i]);
//             ans = max(ans , arr[i] - minprice);   
//         }
//         return ans ;
//     }
// };

