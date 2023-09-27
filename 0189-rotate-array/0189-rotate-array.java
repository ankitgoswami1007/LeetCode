class Solution {
    private void reverse(int[] arr, int s, int e){
        while(s < e){
            int temp = arr[e];
            arr[e] = arr[s];
            arr[s] = temp;
            s++; e--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n ;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
}