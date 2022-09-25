class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int s = 0 , n = letters.size();
        int e = n-1;
        
        while(s <= e){
            
            int m = s + (e-s)/2;
            
            if(target-'a' < letters[m]-'a'){
                e = m-1;
            }
            else 
                s = m+1;
        }
        return letters[s%n];
    }
};