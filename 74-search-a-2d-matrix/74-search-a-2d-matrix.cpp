/*
class Solution {
    bool search(vector<vector<int>>& matrix,int i, int target) {
      
        int low = 0;
        int high = matrix[i].size()-1;
        
        while(low <= high){
            
            int mid = (low+high)/2;
            
            if(matrix[i][mid] == target) return true;
            
            else if(matrix[i][mid] > target) high = mid-1;
            
            else low = mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans = false;
        for(int i = 0 ; i < matrix.size(); i++){
            bool a = search(matrix, i, target);
            if(a == true) return true; 
        }
        return ans;
    }
}; */

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0 , col = cols-1;
        
        while(row < rows && col > -1){
            int curr = matrix[row][col];
            if(curr == target) return true;
            else if(target > curr) row++;
            else col--;
        }
        return false;
    }
};