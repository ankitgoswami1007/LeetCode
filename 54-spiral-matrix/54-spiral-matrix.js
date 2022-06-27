/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    
    let ans = [];
    
    let m = matrix.length;
    let n = matrix[0].length;
    
    let top = 0 , down = m-1;
    let left = 0 , right = n-1;
    let dir = 0;
    
    while(top <= down && left <= right){
        
        if(dir == 0){
            for(let i = left ; i <= right ; i++ ){
                ans.push(matrix[top][i]);
            }
            top = top+1;
        }
        else if(dir == 1) {
            for(let i = top ; i <= down ; i++){
                ans.push(matrix[i][right]);
            }
            right = right-1;
        }
        else if(dir == 2){
            for(let i = right ; i >= left ; i--){
                ans.push(matrix[down][i]);
            }
            down = down-1;
        }
        else if(dir == 3){
            for(let i = down ; i >= top ; i--){
                ans.push(matrix[i][left]);
            }
            left = left+1;
        }
        dir = (dir+1)%4;
    }
    return ans;
    
};