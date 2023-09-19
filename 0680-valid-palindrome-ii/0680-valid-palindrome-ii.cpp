class Solution {
public:
    bool validPalindrome(string s) {
        int start=0;
        int n = s.size();
        int end = n-1;
        int c1 = 0 , c2 = 0;

        while(start <= end){
            if(s[start] == s[end]){
                start++; end--;
            }else{
                start++;
                c1++;
            }
        }
        start = 0;
        end = n-1;
        while(start <= end){
            if(s[start] == s[end]){
                start++; end--;
            }else{
                end--;
                c2++;
            }
        }
        if(c1 == 0 && c2 == 0) return true;
        if(c1 == 1 || c2 == 1) return true;
        return false;
    }
};