class Solution {
public:
    bool isPalindrome(string s) {
       
        transform(s.begin(), s.end(), s.begin(), :: tolower);
        string a;
        for( auto& ch : s){
            
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) a+= ch;
        }
        
        int i = 0 ;
        int j = a.size()-1;
        cout<<a;
        
        while(i < j){
            if(a[i] != a[j]) return false;
            
            i++; j--;  
        }
        return true ;
    }
};