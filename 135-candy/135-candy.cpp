class Solution {
public:
    int candy(vector<int>& arr) {
        
        int ans = 0;
        int n = arr.size() ;
        vector<int> res(n, 1);
        vector<int> res1(n ,1);
        
        for(int i = 1 ; i < n ; i++)
        { if( arr[i-1] < arr[i]) 
            res[i] =  res[i-1] + 1 ; 
            //cout<<res[i]<<"--"<<endl;
        }
        
        for(int i = n-2 ; i >=0 ; i--)
        { if( arr[i] > arr[i+1]) 
            res1[i] = res1[i+1] + 1 ; 
            //cout<<"<>"<<res[i]<<"--"<<endl;
        }
        
        for(int i = 0 ; i < n ; i++)
        { ans+= max(res[i] , res1[i]);
        }
        
       return ans ; 
    }
};