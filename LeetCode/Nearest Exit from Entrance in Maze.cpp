// Question Link - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

// Solution - 

class Solution {
public:
    bool isExit(int i, int j, int ei, int ej, int rows, int cols){
        if(i == ei && j == ej)
            return false;
        return (i == 0 && j >= 0 && j < cols) || (i == rows-1 && j >= 0 && j < cols)
            || (j == 0 && i >= 0 && i < rows) || (j == cols-1 && i >= 0 && i < rows);
    }
    
    bool isValid(int i, int j, vector<vector<char>> & maze, int rows, int cols, vector<vector<bool>> &vis){
        return !(i < 0 || i == rows || j < 0 || j == cols || maze[i][j] == '+' || vis[i][j]);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows=maze.size(), cols=maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int ei=entrance[0], ej=entrance[1];
        q.push({{ei, ej}, 0});
        vis[ei][ej] = true;
        while(!q.empty()){
            int size = (int)q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                int i=node.first.first, j=node.first.second;
                //cout << i << " " << j << " " << node.second << "\n";
                if(isExit(i, j, ei, ej, rows, cols)) return node.second;
                if(isValid(i+1, j, maze, rows, cols, vis)){
                    q.push({{i+1, j}, node.second+1});
                    vis[i+1][j] = true;
                    if(isExit(i+1, j, ei, ej, rows, cols)) return node.second+1;
                }
                if(isValid(i, j+1, maze, rows, cols, vis)){
                    q.push({{i, j+1}, node.second+1});
                    vis[i][j+1] = true;
                    if(isExit(i, j+1, ei, ej, rows, cols)) return node.second+1;
                }
                if(isValid(i, j-1, maze, rows, cols, vis)){
                    q.push({{i, j-1}, node.second+1});
                    vis[i][j-1] = true;
                    if(isExit(i, j-1, ei, ej, rows, cols)) return node.second+1;
                }
                if(isValid(i-1, j, maze, rows, cols, vis)){
                    q.push({{i-1, j}, node.second+1});
                    vis[i-1][j] = true;
                    if(isExit(i-1, j, ei, ej, rows, cols)) return node.second+1;
                }
            }
        }
        return -1;
    }
};

