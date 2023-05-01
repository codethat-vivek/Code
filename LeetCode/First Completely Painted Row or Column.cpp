// Question Link - https://leetcode.com/problems/first-completely-painted-row-or-column/

// Solution - 

#define pii pair<int, int>

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, pii>mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                mp[mat[i][j]] = {i, j};
        }
        unordered_map<int, int>row, col;
        int ans;
        for(int i=0; i<arr.size(); i++){
            pii p = mp[arr[i]];
            row[p.first]++;
            col[p.second]++;
            if(row[p.first] == n || col[p.second] == m){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
