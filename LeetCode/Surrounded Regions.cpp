// Question Link - 

// Solution - 

class Solution {
public:
    
    void borderDFS(vector<vector<char>>&board, vector<vector<bool>>&vis, int i, int j){
        int rows = board.size(), cols = board[0].size();
        if(i<0 || i >= rows || j<0 || j >= cols || board[i][j] != 'O' || vis[i][j])
            return;
        vis[i][j] = true;
        borderDFS(board, vis, i+1, j);
        borderDFS(board, vis, i-1, j);
        borderDFS(board, vis, i, j+1);
        borderDFS(board, vis, i, j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                if(board[i][j] == 'X') vis[i][j] = true;
        }
        for(int i=0; i<rows; i++){
            if(board[i][0] == 'O' && !vis[i][0]) borderDFS(board, vis, i, 0);
            if(board[i][cols-1] == 'O' && !vis[i][cols-1]) borderDFS(board, vis, i, cols-1);
        }
        for(int j=0; j<cols; j++){
            if(board[0][j] == 'O' && !vis[0][j]) borderDFS(board, vis, 0, j);
            if(board[rows-1][j] == 'O' && !vis[rows-1][j]) borderDFS(board, vis, rows-1, j);
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                if(!vis[i][j])board[i][j] = 'X';
        }
    }
};


