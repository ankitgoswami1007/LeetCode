/*class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        
        vector<int> inDeg(n);
        vector<int> imp(n);
        
        for(auto& it : roads){
            inDeg[it[0]]++;
            inDeg[it[1]]++;
        }
        
        vector<pair<int, int>> in;
        
        for(int i = 0 ; i < n ; i++){
            in.push_back({ inDeg[i], i });
        }
        
        sort(begin(in), end(in) , [] (pair<int, int> a , pair<int, int>b){
            return a.first > b.first;
        });
        
        int temp = n ;
        
        for(int i  = 0 ; i < in.size() ; i++){
            imp[in[i].second] = temp--;
        }
        
        for(auto& it : roads){
            ans += (imp[it[0]] + imp[it[1]]);
        }
        
        return ans ;
    }
}; */

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0, x = 1;
        vector<int> degree(n,0);
        for(auto road : roads){
            degree[road[0]]++;
            degree[road[1]]++;
        }
        sort(degree.begin(),degree.end());
        for(auto i : degree){ 
           // cout<<i<<" "<<x<<"\n";
            ans += i * (x++);
           // cout<<ans<<'\n';
        }
        return ans;
    }
};