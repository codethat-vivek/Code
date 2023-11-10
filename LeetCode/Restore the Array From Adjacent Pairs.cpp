// Question Link - https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

// Solution - 

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        map<int, vector<int>> mp;
        map<int, bool>visited;
        
        for(int i=0; i<n; i++){
            int u=adjacentPairs[i][0], v=adjacentPairs[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            visited[u] = false;
            visited[v] = false;
        }
        
        int curr, prev;
        for(auto e : mp){
            if(e.second.size() == 1){
                curr = e.first;
                break;
            }
        }
        
        vector<int>ans;
        ans.push_back(curr);
        visited[curr] = true;
        prev = curr;
        curr = mp[curr][0];
        
        while(visited[curr] == false){
            visited[curr] = true;
            ans.push_back(curr);
        
            if(mp[curr].size() == 1)
                return ans;
            
            int u=mp[curr][0], v=mp[curr][1], temp=curr;
            if(u != prev) curr = u;
            else if(v != prev) curr = v;
            
            prev = temp;
            
        }
        
        return ans;
    }
};
