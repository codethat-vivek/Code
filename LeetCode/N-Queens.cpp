// Question Link - https://leetcode.com/problems/n-queens/

// Solution - 

bool isValid(vector<string>&board, int n, int row, int col){
        int r = row, c = col;
        while(c >= 0){ // West
            if(board[r][c] == 'Q')
                return false;
            c -= 1;
        }
        
        r = row;
        c = col;
        while(r >= 0 && c >= 0){ // North-West
            if(board[r][c] == 'Q')
                return false;
            r -= 1;
            c -= 1;
        }
        
        r = row;
        c = col;
        while(r < n && c >= 0){ // South-West
            if(board[r][c] == 'Q')
                return false;
            r += 1;
            c -= 1;
        }
        
        return true;
    }
    
    void solve(vector<vector<string>> &result, vector<string>&board, int n, int col){
        if(col == n){
            result.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row ++){
            if(isValid(board, n, row, col)){
                board[row][col] = 'Q';
                solve(result, board, n, col+1);
                board[row][col] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string s(n, '.');
        vector<string> board(n, s);
        
        solve(result, board, n, 0);
        
        return result;
        
    }
