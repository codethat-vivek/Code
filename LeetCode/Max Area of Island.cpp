// Question Link - https://leetcode.com/problems/max-area-of-island/

// Solution - 

class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, int i, int j){
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1)
            return 0;
        
        grid[i][j] = 0; // so that we don't count again
        return 1+dfs(grid, i-1, j)+dfs(grid, i+1, j)+dfs(grid, i, j-1)+dfs(grid, i, j+1);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1)
                    ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
