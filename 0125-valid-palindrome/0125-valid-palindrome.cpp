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
        
       
        
          for(int st = 0, end = s.size()-1; st < end ; st++, end--) {
            // Traverse the string from both sides to keep track of start and end indices
            while( ! isalnum(s[st]) && st < end) st++; // Skip non-alphanumeric characters from start
            while( ! isalnum(s[end]) && st < end) end--; // Skip non-alphanumeric characters from end
            // Compare the characters at start and end indices
            if(tolower(s[st]) != tolower(s[end])) return false ; // If not equal, return false 
        }
        return true ; // Else, return true 
    }
};

/*
The time complexity of this code is O(n), where n is the length of the input string s.

In the first approach (commented code), the code performs two passes over the string. The first pass removes non-alphanumeric characters and converts the string to lowercase, which takes O(n) time. The second pass checks if the modified string is a palindrome, which takes O(n/2) time since it compares characters from both ends.
In the second approach (uncommented code), the code uses a two-pointer approach. It starts with a start pointer at the beginning of the string and an end pointer at the end of the string. It moves the pointers towards the center, skipping non-alphanumeric characters, and compares the characters at each step. This approach also takes O(n) time, as it processes each character at most once.
Overall, the time complexity is O(n) in both approaches, where n is the length of the input string s.
*/