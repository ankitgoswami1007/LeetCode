class Solution {
    
    void heapify(vector<int>& arr , int n , int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        
        if( i != largest) {
            swap(arr[i], arr [largest]);
            heapify(arr ,  n ,  largest);
        }

    }
    void buildHeap(vector<int>& arr , int n ){
        
        for(int i = n/2-1 ; i >= 0 ; i--){
            
            heapify(arr , n , i);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        buildHeap(nums , n);
        
        for(int i = n-1 ; i > 0 ; i--){
            swap(nums[0] ,nums[i]);
            heapify(nums , i , 0 );
        }
        
        return nums;
    }
};