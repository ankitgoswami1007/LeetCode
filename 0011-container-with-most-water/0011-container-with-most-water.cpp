class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0 ;
        int r = height.size()-1;
        int mx = 0 ;

        while(l < r){
            int lh = height[l];
            int rh = height[r];
            int min_height = min(lh, rh);
            mx = max(mx , min_height * (r-l));

            if(lh < rh) l++;
            else r--;
        }
        return mx;
        
    }
};