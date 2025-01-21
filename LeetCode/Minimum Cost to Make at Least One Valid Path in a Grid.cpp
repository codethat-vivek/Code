// Question Link - https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

// Solution - 

class Solution {
public:
    const int INF = 1000000000;
    int dijkstra(vector<vector<pair<int, int>>> &adj, int s, int t){
        int n = adj.size();
        vector<int>d(n, INF);
        vector<bool> u(n, false);

        d[s] = 0;
        for (int i = 0; i < n; i++) {
            int v = -1;
            for (int j = 0; j < n; j++) {
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            }

            if (d[v] == INF)
                break;

            u[v] = true;
            for (auto edge : adj[v]) {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to])
                    d[to] = d[v] + len; // RELAXATION
            }
        }

        return d[t];
    }

    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<pair<int, int>>>adj(rows*cols);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int currentIndex = i * cols + j;

                if (grid[i][j] == 1 && j + 1 < cols) {
                    adj[currentIndex].push_back({i * cols + j + 1, 0});
                } else if (grid[i][j] != 1 && j + 1 < cols) {
                    adj[currentIndex].push_back({i * cols + j + 1, 1}); // 1 cost if not moving right
                }

                // Move Left (2)
                if (grid[i][j] == 2 && j - 1 >= 0) {
                    adj[currentIndex].push_back({i * cols + j - 1, 0});
                } else if (grid[i][j] != 2 && j - 1 >= 0) {
                    adj[currentIndex].push_back({i * cols + j - 1, 1}); // 1 cost if not moving left
                }

                // Move Down (3)
                if (grid[i][j] == 3 && i + 1 < rows) {
                    adj[currentIndex].push_back({(i + 1) * cols + j, 0}); 
                } else if (grid[i][j] != 3 && i + 1 < rows) {
                    adj[currentIndex].push_back({(i + 1) * cols + j, 1}); // 1 cost if not moving down
                }

                // Move Up (4)
                if (grid[i][j] == 4 && i - 1 >= 0) {
                    adj[currentIndex].push_back({(i - 1) * cols + j, 0}); 
                } else if (grid[i][j] != 4 && i - 1 >= 0) {
                    adj[currentIndex].push_back({(i - 1) * cols + j, 1}); // 1 cost if not moving up
                }
            }
        }

        return dijkstra(adj, 0, rows*cols-1);
        
    }
};
