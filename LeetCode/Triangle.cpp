// Question Link - https://leetcode.com/problems/triangle/

// Solution - 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][i-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int ans = 100000;
        for(int j=0; j<n; j++){
            if(triangle[n-1][j] < ans)
                ans = triangle[n-1][j];
        }
        return ans;
    }
};
