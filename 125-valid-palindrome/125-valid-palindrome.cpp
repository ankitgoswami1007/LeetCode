class Solution {
public:
    bool isPalindrome(string s) {
       
       /* transform(s.begin(), s.end(), s.begin(), :: tolower);
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
        return true ; */
        
       // int st = 0 , end = s.size()-1;
        
       /* while(st < end) {
            
            if( ! isalnum(s[st])) st++;
            else if( ! isalnum(s[end])) end--;
            else{
               if(tolower(s[st++]) != tolower(s[end--])) return false ;
            } 
        }
        return true ; */
        
         for(int st = 0, end = s.size()-1; st < end ; st++, end--) {
            
            while( ! isalnum(s[st]) && st < end) st++;
            while( ! isalnum(s[end]) && st < end) end--;
            if(tolower(s[st]) != tolower(s[end])) return false ;
             
        }
        return true ; 
    }
};