// Question Link - https://leetcode.com/problems/find-if-path-exists-in-graph/

// Solution - 

class Solution {
public:
    
    bool check(vector<int>adj[], vector<bool>&vis, int src, int dest){
        if(src == dest)
            return true;
        vis[src] = true;
        for(auto child : adj[src]){
            if(!vis[child] && check(adj, vis, child, dest))
                return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n, false);
        return check(adj, vis, source, destination);
    }
};
