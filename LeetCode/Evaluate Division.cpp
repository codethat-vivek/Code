// Question Link - https://leetcode.com/problems/evaluate-division/

// Solution - 

class Solution {
public:
    
    double bfs(vector<vector<int>> adj, vector<vector<double>> &gph, int n, int startNode, int endNode){
        if(startNode == endNode)
            return 1;
        queue<int>q;
        q.push(startNode);
        vector<int>visited(n, 0);
        visited[startNode] = 1;
        vector<int>parent(n);
        bool finished = false;
        while(!q.empty() && !finished){
            int len = q.size();
            while(len--){
                int topNode = q.front();
                q.pop();
                if(topNode == endNode){
                    finished = true;
                    break;
                }
                for(int child : adj[topNode]){
                    if(!visited[child]){
                        q.push(child);
                        visited[child] = 1;
                        parent[child] = topNode;
                    }
                }
            }
        }
        
        //endNode -- a -- b -- c -- startNode
        if(!finished)
            return -1;
        
        double ans = 1;
        int node = endNode;
        while(node != startNode){
            //cout << node << " " << parent[node] << " " << gph[parent[node]][node] << endl;
            if(gph[parent[node]][node] != -1)
                ans *= gph[parent[node]][node];
            else
                ans /= gph[node][parent[node]];
            node = parent[node];
        }
        
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        unordered_map<string, int>um;
        vector<vector<int>> adj(2*n, vector<int>());
        vector<vector<double>> gph(2*n, vector<double>(2*n, -1));
        int i = 0;
        for(int x=0; x<n; x++){
            auto v = equations[x];
            if(um.find(v[0]) == um.end())
                um[v[0]] = i++;
            if(um.find(v[1]) == um.end())
                um[v[1]] = i++;
            adj[um[v[0]]].push_back(um[v[1]]);
            adj[um[v[1]]].push_back(um[v[0]]);
            gph[um[v[0]]][um[v[1]]] = values[x];
        }
        
        vector<double>ans;
        for(vector<string> &s : queries){
            if(um.find(s[0]) == um.end() || um.find(s[1]) == um.end())
                ans.push_back(-1);
            else
                ans.push_back(bfs(adj, gph, i, um[s[0]], um[s[1]]));
        }
        
        return ans;
    }
};
