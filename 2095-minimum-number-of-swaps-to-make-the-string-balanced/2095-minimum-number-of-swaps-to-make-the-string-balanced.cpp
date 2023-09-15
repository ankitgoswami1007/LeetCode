class Solution {
public:
    int minSwaps(string s) {

        int mx = INT_MIN;
        int extra_closing = 0 ;

        for(auto ch : s){
            if(ch == ']'){
                extra_closing++;
            }else{
                extra_closing--;
            }
            mx = max(mx, extra_closing);
        }
        return (mx+1)/2;
    }
};