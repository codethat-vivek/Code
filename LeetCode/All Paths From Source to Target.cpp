// Question Link - https://leetcode.com/problems/all-paths-from-source-to-target/

// Solution - 

class Solution {
public:
    vector<vector<int>> helper(vector<vector<int>>&graph, int src, int dest){
        if(src == dest) return {{dest}};
        vector<vector<int>> ans;
        for(auto each : graph[src]){
            vector<vector<int>> temp = helper(graph, each, dest);
            for(auto rows : temp){
                rows.insert(rows.begin(), src);
                ans.push_back(rows);
            }
        }
        return ans;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return helper(graph, 0, graph.size()-1);
    }
};
