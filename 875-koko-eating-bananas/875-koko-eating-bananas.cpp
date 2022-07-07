class Solution {
    bool isPossible(vector<int>& piles, int h, int k){
        long long sum = 0 ;
        for(int i = 0 ; i < piles.size() ; i++){
            sum += (piles[i]%k == 0) ? piles[i]/k : (piles[i]/k)+1;
        }
        if(sum <= h) return true;
        return false;
        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        if(n > h) return -1;
        
        int mx = INT_MIN;
        
        for(auto& p : piles){
            mx = max(p , mx);
        }
        
        if(h == n) return mx ;
        
        int high = 1000000000;
        int low = 1 ;
        int k = INT_MAX;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(isPossible( piles,  h,  mid)){
                k = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return k; 
    }
};

