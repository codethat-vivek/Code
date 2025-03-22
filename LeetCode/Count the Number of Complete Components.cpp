// Question Link - https://leetcode.com/problems/count-the-number-of-complete-components/description/

// Solution - 

class Solution {
public:
    int rootDegree;
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int &compSize){
        vis[node] = 1;
        compSize ++;
        bool flag = true;
        for(int child : adj[node]){
            if(vis[child] == 0){
                bool b = dfs(adj, vis, child, compSize);
                if(!b) flag = false;
            }
                
        }
        if(flag == false || adj[node].size() != rootDegree)
            return false;
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(vector<int> &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>vis(n, 0);
        int ans = 0, compSize;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                compSize = 0;
                rootDegree = adj[i].size();
                bool b = dfs(adj, vis, i, compSize);
                if(b && rootDegree == compSize - 1)
                    ans++;
            }
                
        }

        return ans;

    }
};
