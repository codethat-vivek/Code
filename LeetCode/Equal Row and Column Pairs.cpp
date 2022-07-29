// Question Link - https://leetcode.com/problems/equal-row-and-column-pairs/

// Solution - 

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int>mp_rows;
        for(auto x : grid)
            mp_rows[x] += 1;

        map<vector<int>, int>mp_cols;
        for(int j=0; j<grid[0].size(); j++){
            vector<int>v;
            for(int i=0; i<grid.size(); i++)
                v.push_back(grid[i][j]);
            mp_cols[v] += 1;
        }
        
        int ans = 0;
        for(auto &x : mp_cols){
            if(mp_rows.find(x.first) != mp_rows.end())
                ans += (mp_rows[x.first]*x.second);
        }
        
        return ans;
        
    }
};
