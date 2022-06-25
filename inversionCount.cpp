// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int merge(int arr[] , int temp[], int left , int mid , int right){
    int i , j , k, count = 0 ;
    
    i = left;
    j = mid;
    k = left;
    
    while(i <= mid-1 && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count += (mid-i);
        }
    }
    while(i <= mid-1){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    
    for(i = left ; i <= right ; i++){
        arr[i] = temp[i];
    }
    
    //     for( i = left ; i < right ; i++){
    //     cout<<temp[i];
    // }
    return count;
}

int mergeSort(int arr[], int temp [], int left, int right){
    
    int mid = 0 ;
    int count = 0 ;
    
    if(right > left){
        
        mid = (right + left)/2;
        
        count += mergeSort(arr, temp, left , mid);
        count += mergeSort(arr, temp, mid+1, right);
        
        count += merge(arr, temp , left , mid+1, right);
    }
    return count;
}

int main() {
    // Write C++ code here
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = mergeSort(arr, temp, 0, n-1);

    cout << ans<<"\n";

    return 0;
}