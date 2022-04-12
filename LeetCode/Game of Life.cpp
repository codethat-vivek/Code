// Question Link - https://leetcode.com/problems/game-of-life/

// Solution - 

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>>grid(rows, vector<int>(cols, 0));
        int liveNeighbours = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i-1 >= 0){
                    if(j-1 >= 0 && board[i-1][j-1]) liveNeighbours ++;
                    if(board[i-1][j])liveNeighbours ++;
                    if(j+1 < cols && board[i-1][j+1])liveNeighbours ++;
                }
                if(j-1 >= 0 && board[i][j-1])liveNeighbours++;
                if(j+1 < cols && board[i][j+1])liveNeighbours ++;
                if(i+1 < rows){
                    if(j-1 >= 0 && board[i+1][j-1])liveNeighbours++;
                    if(board[i+1][j])liveNeighbours++;
                    if(j+1 < cols && board[i+1][j+1])liveNeighbours++;
                }
                
                if(board[i][j]){// cell is live
                    if(liveNeighbours == 2 || liveNeighbours == 3)
                        grid[i][j] = 1;
                }
                else{
                    if(liveNeighbours == 3)
                        grid[i][j] = 1;
                }
                liveNeighbours = 0;
            }
            
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                board[i][j] = grid[i][j];
            }
        }
        return;
    }
};
