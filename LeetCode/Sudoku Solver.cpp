// Question Link - 

// Solution - 

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int x, int y, char& ch) {
        for(int i=0; i<9; i++) // checking in the same row and col for duplicacy
            if(board[x][i] == ch || board[i][y] == ch) return false;
        
        // coordinate of top left element of that grid
        int topLeftI = x/3 * 3;
        int topLeftJ = y/3 * 3;
        for(int k = 0; k<3; k++) {
            for(int l = 0; l<3; l++)
                if(board[topLeftI + k][topLeftJ + l] == ch) return false;
        }
        return true;
    }
    
    bool sudokuSolver(vector<vector<char>> &board, int i, int j){
        if(i == 9) // finished filling the board
            return true;
        if(j == 9) 
            return sudokuSolver(board, i+1, 0); // now we need to fill in the next row and first col
        if(board[i][j] != '.')
            return sudokuSolver(board, i, j+1); // if there is a digit then just solve further
        for(char ch = '1'; ch <= '9'; ch++){
            if(isValid(board, i, j, ch)){// checking if ch is possible to fill
                board[i][j] = ch; // fill ch in board[i][j]
                if(sudokuSolver(board, i, j+1)) // if next position returns true, then it means that ch is filled correctly at position board[i][j] and we can just return true
                    return true;
                board[i][j] = '.'; // if not then we need to backtrack by filling board[i][j] with '.'
            }
        }
        return false; // this basically triggers backtracking
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};
