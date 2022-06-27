class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans ;
        
        int m = matrix.size();
        int n = matrix[0].size() ; 
        int row = m-1 ; 
        int col = n-1 ;
        int direction = 1;
     
        int r = 0 , c = 0 ;
        while ( r <= row  && c <= col) {
            if(direction == 1){
                for(int  j = c ; j <= col ; j++) 
                    ans.push_back(matrix[r][j]);
                r++; 
                direction = 2;
            }
             
            else if(direction == 2){
                for(int i = r; i <= row ; i++) 
                    ans.push_back(matrix[i][col]);
                col--;
                direction = 3;
            }
            
            else if(direction == 3){
               for(int j = col ; j >= c  ; j--) 
                   ans.push_back(matrix[row][j]) ; 
                   row--; 
                direction = 4;
               
            }
            else if(direction == 4){
                for( int i = row ; i >= r ; i--) 
                    ans.push_back(matrix[i][c]);
                c++;
                direction = 1;
            }
            
               
        }
        return ans ;
    }
};