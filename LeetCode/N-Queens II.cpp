// Question Link - https://leetcode.com/problems/n-queens-ii/

// Solution - 

class Solution {
public:
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
    
    void solve(int &ans, vector<string>&board, int n, int col){
        if(col == n){
            ans += 1;
            return;
        }
        
        for(int row = 0; row < n; row ++){
            if(isValid(board, n, row, col)){
                board[row][col] = 'Q';
                solve(ans, board, n, col+1);
                board[row][col] = '.';
            }
        }
        
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        string s(n, '.');
        vector<string> board(n, s);
        
        solve(ans, board, n, 0);
        
        return ans;
    }
};
