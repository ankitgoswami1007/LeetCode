class Solution {
    
    int partion(vector<int>& a , int l , int h){
        
        int pivot = a[l];
        
        int i = l , j = h;
        
        while(i < j) {
            
            do{
                i++;
            }while(a[i] <= pivot);
            
            do{
                j--;
            }while(a[j] > pivot);
            
            if(i < j) swap(a[i], a[j]);   
        }
        
        swap(a[l], a[j]);
        return j; 
    }
    
    void quickSort(vector<int>& nums , int low , int high) {
        
        if(low < high) {
            int j = partion(nums , low , high);
            quickSort(nums , low , j);
            quickSort(nums, j+1 , high);
        }
    }
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 1) return;
        
        int mx = INT_MAX ;
        nums.push_back(mx);
        
        int l = 0 ;
        int h = n;
        
        quickSort(nums , l , h); 
        nums.pop_back();
        return ;   
    }
};