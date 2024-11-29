// Question Link - https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

// Solution - 

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        vector<vector<int>> visited(r, vector<int>(c, 0));
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dist[0][0] = 0;
        visited[0][0] = 1;
        
        vector<vector<int>>dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while(!dq.empty()){
            int len = dq.size();
            while(len--){
                auto [x, y] = dq.front();
                dq.pop_front();
                for(auto &dir : dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == 0){
                        visited[nx][ny] = 1;
                        if(grid[nx][ny] == 1){
                            dist[nx][ny] = dist[x][y] + 1;
                            dq.push_back({nx, ny});
                        }
                        else{
                            dist[nx][ny] = dist[x][y];
                            dq.push_front({nx, ny});
                        }
                            
                    }
                }
            }
        }
        return dist[r-1][c-1];
    }
};
