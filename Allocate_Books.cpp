#include <bits/stdc++.h>
using namespace std;
bool isfeasable(vector<int> a, int k , int res ){
    
    int student = 1 ;
    int sum = 0 ;
    for(int i = 0 ; i < a.size() ; i++){
        if(sum + a[i] > res){
            student++;
            sum = a[i];
        }
        else{
            sum += a[i];
        }
    }
    return student <= k;
}

int books(vector<int> &a, int k) {
    if(a.size() < k) return -1;
    int max = accumulate(a.begin(), a.end(), 0);
    int min = *max_element(a.begin() , a.end());
    int res = 0;
    while(min <= max){
        
        int mid = (min+max)/2;
        
        if(isfeasable(a , k , mid)){
            res = mid ;
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    return res;
}

int main(){

    vector<int> arr;
    int k ;
    //[[1,3],[2,6],[8,10],[15,18]]
    int n;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cin>> k ;
    int res = books( arr , k);

    
    cout<< "minimum possible number: "<< res<<"\n";
    
    return 0;
}
