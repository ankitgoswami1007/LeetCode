class Solution {
public:
int maxProfit(vector<int>& arr) {
int ans = 0;
int minprice = INT_MAX;
for(int i = 0 ; i < arr.size() ; i++){
minprice = min(minprice, arr[i]);
ans = max(ans , arr[i] - minprice);
}
return ans ;
}
};