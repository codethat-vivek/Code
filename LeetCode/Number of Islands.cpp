// Question Link - https://leetcode.com/problems/number-of-islands/

// Solution - 

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>&vis){
        int rows = grid.size(), cols = grid[0].size();
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j] != '1' || vis[i][j])
            return;
        vis[i][j] = true;
        
        dfs(grid, i-1, j, vis);
        dfs(grid, i+1, j, vis);
        dfs(grid, i, j+1, vis);
        dfs(grid, i, j-1, vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>>vis(301, vector<bool>(301, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, vis);
                    islands++;
                }
            }
        }
        return islands;
    }
};
