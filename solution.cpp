#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  /*  int kthSmallest(vector<vector<int>>& matrix, int k) {
       priority_queue<int > pq;
        int count = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                // if(count < k){
                //    pq.push(matrix[i][j]);
                //     cout<<matrix[i][j]<<"--";
                //     count++;
                // }
                // else if(pq.top() > matrix[i][j] ){
                //     pq.pop();
                //     pq.push(matrix[i][j]);
                // }
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
            
        } 
        return pq.top() ;
    } */
    
    int helper(vector<vector<int> >& matrix , int mid){
        
        int count = 0 ;
        int n = matrix.size();
        int i = n-1 , j = 0 ;
        
        while(i >= 0 && j < n){
            
            if(matrix[i][j] > mid) i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        int n = matrix.size();
        
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high){
            
            int mid = low +(high - low)/2;
            int count = 0;
            for(int i = 0 ; i < n ; i++){
             count += upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin(); 
             //cout<<mid<<"--"<< upper_bound(matrix[i].begin() , matrix[i].end() , mid) - matrix[i].begin()<<endl;   
            } 
           // count  = helper(matrix , mid);
            if(count < k) low = mid+1;
            else high = mid;
        }
        return low;
    }
};

int main(){

    Solution ob;

    //matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
   //int k =8;
   //vector<vector<int> >v ;
                        //     { { 1, 5, 9 }, 
                        //      { 10, 11, 13 }, 
                        //      { 12, 13, 15 }
                        //    };
    // vector<int> a ;
    // a.push_back(1); a.push_back(5); a.push_back(9);
    // v.push_back(a);
    // vector<int> b ;
    // b.push_back(10); b.push_back(11); b.push_back(13);
    // v.push_back(b);
    // vector<int> c ;
    // c.push_back(12); c.push_back(13); c.push_back(15);
    // v.push_back(c);
    int k ;
    cout<<"Enter k value : ";
    cin >> k ;
    cout<<"Enter size of matrix  : ";
    int n ;
    cin >> n;
    vector<vector<int> >v ;
    int val;
    for(int i = 0; i < n; i++){
    vector<int> temp;
    cout<<"[ ";
    for(int j = 0; j < n; j++){
        cin >> val;
        temp.push_back(val);
    }
    cout<<"]"<< endl;
    v.push_back(temp);
    temp.clear();
}

  
   cout<<"kthSmallest :  "<< ob.kthSmallest(v, k)<<endl;


}