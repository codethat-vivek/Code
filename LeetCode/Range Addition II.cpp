// Question Link - https://leetcode.com/problems/range-addition-ii/

// Solution - 

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ans = m*n;
        if(ops.size() == 0)
            return ans;
        int minX = INT_MAX, minY = INT_MAX;
        for(auto x : ops){
            minX = min(minX, x[0]);
            minY = min(minY, x[1]);
        }
        return minX*minY;
    }
};
