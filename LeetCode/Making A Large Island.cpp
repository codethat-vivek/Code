// Question Link - https://leetcode.com/problems/making-a-large-island/

// Solution - 

class DSU{
    public:
    vector<int>size;
    vector<int>parent;
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++)
            parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    int doUnion(int u, int v){
        int par_u = findUPar(u), par_v = findUPar(v);
        if(par_u == par_v) return size[par_u];
        if(size[par_u] > size[par_v]){
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        return max(size[par_u], size[par_v]);
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == 1)
            return 1;

        DSU dsu(r*c);
        vector<int>rows{0, 1, -1, 0};
        vector<int>cols{1, 0, 0, -1};
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    for(int d=0; d<4; d++){
                        int nx = i+rows[d], ny = j+cols[d];
                        if(nx >= 0 && nx < r and ny >= 0 && ny < c){
                            if(grid[nx][ny] == 1){
                                ans = max(ans, dsu.doUnion(i*c + j, nx*c+ny));
                            }
                        }
                    }
                }
            }
        }

        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 0){
                    int nbr_size = 0;
                    set<int>st;
                    for(int d=0; d<4; d++){
                        int nx=i+rows[d], ny=j+cols[d];
                        if(nx >= 0 && nx < r and ny >= 0 && ny < c){
                            if(grid[nx][ny] == 1)
                                st.insert(dsu.findUPar(nx*c+ny));
                        }
                    }
                    for(auto &p : st)
                        nbr_size += dsu.size[p];
                    ans = max(ans, nbr_size + 1);
                }
            }
        }

        return ans;
    }
};
