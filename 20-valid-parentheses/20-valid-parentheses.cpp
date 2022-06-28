class Solution {
public:
    bool isValid(string s) {
        
        stack <char> ss;
        
       /* for( int i = 0 ; i < s.size() ; i++){
            
            char ch = s[i];
            
            switch(ch){
                case '(': 
                case '{':
                case '[':
                     ss.push(ch);
                     break;
                    
                    
                case ')':
                    if (ss.empty() || ss.top() != '(') return false;
                    else ss.pop();
                    break;
                case '}':
                    if (ss.empty() || ss.top() != '{') return false;
                    else ss.pop();
                    break;
                case ']':
                    if (ss.empty() || ss.top() != '[') return false;
                    else ss.pop();
                    break;
            }
        
        }
        if (ss.empty())
            return true; 
        else
            return false ;*/
        
        for (int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            
            switch(ch){
                case '{': ss.push('}') ; break;
                case '(': ss.push(')') ; break;
                case '[': ss.push(']'); break;
                default:
                    if(ss.empty() || ch != ss.top()) return false;
                    else ss.pop();
            }
        }
        return ss.size() == 0;
    }
};