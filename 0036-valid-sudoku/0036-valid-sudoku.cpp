class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<string> seen;

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(board[row][col] != '.'){

                    string r = to_string(row);
                    string c = to_string(col);
                    string rc = to_string((row/3)*3+col/3);

                    if(seen.count("row"+r+board[row][col]) || seen.count("col"+c+board[row][col]) ) {
                        return false;
                    }
                    else if(seen.count("box"+rc+board[row][col])){
                        return false;
                    }
                    else{
                        seen.insert("row"+r+board[row][col]);
                        seen.insert("col"+c+board[row][col]);
                        seen.insert("box"+rc+board[row][col]);
                    }

                }
            }
        }
        return true;
    }
};