// Question Link - https://leetcode.com/problems/pascals-triangle/submissions/

// Solution - 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};
        vector<vector<int>>ans = {{1}, {1, 1}};
        for(int i=2; i<numRows; i++){
            vector<int>t(i+1);
            t[0] = 1;
            t[i] = 1;
            for(int j=1; j<t.size()-1; j++)
                t[j] = ans[i-1][j-1] + ans[i-1][j];
            ans.push_back(t);
        }
        return ans;
    }
};
