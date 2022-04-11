// Question Link - https://leetcode.com/problems/shift-2d-grid/

// Solution - 

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>>ans(rows, vector<int>(cols));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int newJ = (j+k)%cols;
                int newI = (i+((j+k)/cols)) % rows;
                ans[newI][newJ] = grid[i][j];
            }
        }
        return ans;
    }
};
