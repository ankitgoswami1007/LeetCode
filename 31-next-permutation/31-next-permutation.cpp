class Solution {
public:
    void nextPermutation(vector<int>& arr) { 
        
        int  n = arr.size()-1;
        int i = n-1;
        int ind = -1;
        while(i>=0){
            if(arr[i] < arr[i+1]) {break ;}
            i--;
        }
        ind = i ;
        
        if(i < 0 ) {reverse(arr.begin() , arr.end());}
        else{
        i = n ;
        while(i>=0){
            if(arr[ind] < arr[i]) break;
            i--;
        }
        swap(arr[ind] , arr[i] );
        reverse(arr.begin() +ind +1, arr.end());
        }    
    }
};