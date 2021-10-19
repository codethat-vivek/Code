// Question Link - https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Solution - 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), ans = INT_MAX;
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        grid[0][0] = -1;
        while(!q.empty()){
            int len = (int)q.size();
            while(len--){
                auto p = q.front();
                q.pop();
                int i=p.first.first, j=p.first.second, val=p.second;
                if(i == n-1 && j == n-1)ans = min(ans, val);
                if(i >= 0 && j+1 >= 0 && i < n && j+1 < n && grid[i][j+1] == 0){
                    q.push({{i, j+1}, val+1});
                    //cout << i << " " << j+1 << endl;
                    grid[i][j+1] = -1;
                }
                
                if(i >= 0 && j-1 >= 0 && i < n && j-1 < n && grid[i][j-1] == 0){
                    q.push({{i, j-1}, val+1});
                    //cout << i << " " << j-1 << endl;
                    grid[i][j-1] = -1;
                }
                
                if(i-1 >= 0 && j >= 0 && i-1 < n && j < n && grid[i-1][j] == 0){
                    q.push({{i-1, j}, val+1});
                    //cout << i-1 << " " << j << endl;
                    grid[i-1][j] = -1;
                }
                
                if(i+1 >= 0 && j >= 0 && i+1 < n && j < n && grid[i+1][j] == 0){
                    q.push({{i+1, j}, val+1});
                    //cout << i+1 << " " << j << endl;
                    grid[i+1][j] = -1;
                }
                
                if(i+1 >= 0 && j+1 >= 0 && i+1 < n && j+1 < n && grid[i+1][j+1] == 0){
                    q.push({{i+1, j+1}, val+1});
                    //cout << i+1 << " " << j+1 << endl;
                    grid[i+1][j+1] = -1; 
                }
                
                if(i-1 >= 0 && j-1 >= 0 && i-1 < n && j-1 < n && grid[i-1][j-1] == 0){
                    q.push({{i-1, j-1}, val+1});
                    //cout << i-1 << " " << j-1 << endl;
                    grid[i-1][j-1] = -1; 
                }
                
                if(i-1 >= 0 && j+1 >= 0 && i-1 < n && j+1 < n && grid[i-1][j+1] == 0){
                    q.push({{i-1, j+1}, val+1});
                    //cout << i-1 << " " << j+1 << endl;
                    grid[i-1][j+1] = -1;
                }
                
                if(i+1 >= 0 && j-1 >= 0 && i+1 < n && j-1 < n && grid[i+1][j-1] == 0){
                    q.push({{i+1, j-1}, val+1});
                    //cout << i+1 << " " << j-1 << endl;
                    grid[i+1][j-1] = -1; 
                }
            }
            //cout << "----------------------" << endl;
        }
        if(ans == INT_MAX) return -1;
            return ans;
    }
};
