// Question Link - https://leetcode.com/problems/rotting-oranges/

// Solution - 

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q; // for storing the indices of rotten oranges
        int rows = grid.size(), cols = grid[0].size(), minutes = 0, total = 0, cnt = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    total++;
            }
        }
        total += (int)q.size(); // total is the no. of rotten oranges + no. of fresh oranges
        
        while(!q.empty()){
            int len = (int)q.size();
            cnt += len;
            
            while(len--){
                pair<int, int>p = q.front();
                q.pop();
                int i=p.first, j=p.second;
                
                // right
                if(i >= 0 && j+1 >= 0 && i < rows && j+1 < cols && grid[i][j+1] == 1){
                    q.push({i, j+1});
                    grid[i][j+1] = 2; // adding in queue and changing the status as rotten
                }
                // left
                if(i >= 0 && j-1 >= 0 && i < rows && j-1 < cols && grid[i][j-1] == 1){
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                }
                // top 
                if(i-1 >= 0 && j >= 0 && i-1 < rows && j < cols && grid[i-1][j] == 1){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                }
                // bottom
                if(i+1 >= 0 && j >= 0 && i+1 < rows && j < cols && grid[i+1][j] == 1){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                }
            }
            if(!q.empty())
                minutes++;
            
        }
        if(total == cnt) // if total(rotten + fresh) == cnt then it means we have an answer
            return minutes;
        return -1; 
    }
};
