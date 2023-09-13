class Solution {
    
    int partion(vector<int>& arr , int l , int h){
        
        int pivot = arr[h];
        
        int i = l-1;
        
        for(int j = l ; j < h ; j++){
            if(arr[j] <= pivot){
                i++;
                swap(arr[i], arr[j]);
            }
               
        }
        i++;
        arr[h] = arr[i];
        arr[i] = pivot;
        return i; 
    }
    
    void quickSort(vector<int>& nums , int low , int high) {
        
        if(low >= high) {
            return;
        }
            int j = partion(nums , low , high);
            quickSort(nums , low , j-1);
            quickSort(nums, j+1 , high);
        
    }
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1) return;
   
        int l = 0 ;
        int h = n-1;
        
        quickSort(nums , l , h); 
        return ;   
    }
}; 
/*
class Solution {
    public:
    void sortColors(vector<int>& nums) 
    {
        int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--;
            }
        }
    }
}; */