/*class Solution {
public:
    int merge(int arr[], int temp[] , int s , int mid , int e){
        
        int count = 0 ;
        int j = mid+1;
        for(int i = s ; i <= mid ; i++){
            while( j <= e && (arr[i] > 2LL*arr[j])){
                j++;
            }
            count += (j-(mid+1));
        }
        int i = s;
        j = mid+1;
        int k = s;
        while( i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(int i = s ; i <= e ; i++){
            arr[i] = temp[i];
        }
        
        return  count ;
    }
    int mergesort(int arr[] , int temp[] , int s , int e){
        int mid , count = 0 ;
        if(s >= e) return 0;
            
            mid = (s+e)/2;
            
            count += mergesort(arr , temp , s , mid) + mergesort(arr , temp , mid+1 , e);
            
            count += merge(arr , temp , s , mid , e);    

        return count ;
    }
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        
        int* arr = new int[n];
        int* temp = new int[n];
        
        for(int i = 0 ; i < n ; i++ ){
            arr[i] = nums[i];
        }
        
        int ans = mergesort(arr , temp , 0 , n-1);
        return ans ;
        
    }
};*/


    
 








//----------------------- 3rd approach

class Solution {
private:
    int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end){

        // two pointers;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
        
        
        
        //every step sort
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid);
        mergeSort(nums,mid+1,end);
        
        checkCount(nums,start,mid,end);
        return;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
}; 
