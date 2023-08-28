/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        
        map <int,int> mp ;
        
        int n = num2.size();
        int m = num1.size();
        
        vector<int> ans(n , 0);
        vector<int> res(m , 0);
        
        
        
        stack<int> st ; */
       
         //1nd approach --- from left to right and using indexing
        /*st.push(0);
        
        for(int i = 1 ; i < num2.size() ; i++){
            
            while(!st.empty() && num2[i] > num2[st.top()]){
                int pos = st.top();
                ans[pos] = num2[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int pos = st.top();
            ans[pos] = -1;
            st.pop();   
        } */
        // 2nd approach --- from right to left and using variable
   /*     st.push(num2[n-1]);
        ans[n-1] = -1 ;
        
        for(int i = n-2 ; i >= 0 ; i--){
            
            while(!st.empty() and num2[i] >= st.top()){
                st.pop();
            }
            if(st.empty() == true){
                ans[i] = -1 ;
            }
            else{
                ans[i] = st.top();
            }
            st.push(num2[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            mp[num2[i]] = ans[i] ;
        }
        
        for(int i = 0 ; i < m ; i++){
            
            if(mp.find(num1[i]) != mp.end()){
                res[i] = mp[num1[i]];
            }
        }
        
        return res ;
    }
}; */


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        unordered_map<int,int> mp ;
        int m = num1.size();
        vector<int> res(m , -1);
        stack<int> st ;
        
        for(auto& n: num2){
            
            while(!st.empty() && n > st.top()){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        for(int i = 0 ; i < m ; i++ ){
            
            if(mp.find(num1[i]) != mp.end()){
                res[i] = mp[num1[i]];
            }
        }
        
      return res ;
        
    }
};