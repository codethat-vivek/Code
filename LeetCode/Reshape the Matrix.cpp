// Question Link - https://leetcode.com/problems/reshape-the-matrix/

// Solution - 

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int a=0, b=0;
        int rows = mat.size();
        int cols = mat[0].size();
        if (r * c != rows*cols)
            return mat;
        vector<vector<int>> ans;
        for(int i=0; i<r; i++){
            ans.push_back({});
            for(int j=0; j<c; j++){
                ans[i].push_back(mat[a][b++]);
                if(b == cols)
                {
                    b = 0;
                    a ++;
                }
            }
        }
        return ans;
    }
};
