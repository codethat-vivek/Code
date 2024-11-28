// Question Link - https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

// Solution - 

class Solution {
public:
    
    int bfs(vector<vector<int>> &adj, int n){
        vector<int>parent(n, -1);
        queue<int>q;
        q.push(0);
        
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int topNode = q.front();
                q.pop();
                for(int child : adj[topNode]){
                    if(parent[child]  == -1){
                        parent[child] = topNode;
                        q.push(child);    
                    } 
                }
            }
        }
        int node = n-1, length = 0;
        while(node != 0){
            length++;
            node = parent[node];
        }
        
        return length;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int>parent(n, -1);
        for(int i=0; i<n-1; i++)
            adj[i].push_back(i+1);
        
        vector<int>ans;
        for(auto &e : queries){
            adj[e[0]].push_back(e[1]);
            int len = bfs(adj, n);
            ans.push_back(len);
        }
        
        return ans;
        
    }
};
