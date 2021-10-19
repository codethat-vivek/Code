// Question Link - https://leetcode.com/problems/number-of-provinces/

// Solution - 

class Solution {
public:
    void dfs(int node , vector<vector<int>> &isConnected ,  vector<int> &vis, int n){
        vis[node] = true;
        for(int i=0 ; i<n; i++){
            if(!vis[i] && isConnected[node][i] == 1)
                dfs(i,isConnected, vis, n);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n ,0);
        int provinces = 0 ;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                provinces++;
                dfs(i,isConnected,vis,n);
            }
        }
        return provinces;
    }
};
