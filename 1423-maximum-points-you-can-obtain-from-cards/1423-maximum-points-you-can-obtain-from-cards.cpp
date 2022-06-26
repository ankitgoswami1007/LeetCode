class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        if(n < k ) return 0;
        int sum = 0 , i = 0 , j = 0;
        int finalSum = 0, kSum ;
        int r = n-k;
        for(i = r ; i < n ; i++){
            // if(i < k+1) kSum += cardPoints[i];
            // sum += cardPoints[i];
            finalSum += cardPoints[i];
        }
        
        finalSum = sum - kSum;
        cout<<finalSum;
        int total = finalSum;
        int l = 0 ;
        
        
        while(r < n ){
            total += cardPoints[l] - cardPoints[r];
            finalSum = max(finalSum , total);
            l++; r++;
        }
        
        return finalSum;
    }
};