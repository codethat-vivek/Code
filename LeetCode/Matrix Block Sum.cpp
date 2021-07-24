// Question Link - https://leetcode.com/problems/matrix-block-sum/

// Solution - 

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=1; j<cols; j++)
                mat[i][j] += mat[i][j-1];
        }
        for(int j=0; j<cols; j++){
            for(int i=1; i<rows; i++)
                mat[i][j] += mat[i-1][j];
        }
        
        vector<vector<int>>ans = mat;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans[i][j] = mat[min(i+k, rows-1)][min(j+k, cols-1)];
                if(j-k > 0)
                    ans[i][j]  -= mat[min(i+k, rows-1)][j-k-1];
                if(i-k > 0)
                    ans[i][j] -= mat[i-k-1][min(j+k, cols-1)];
                if(j-k > 0 && i-k > 0)
                    ans[i][j] += mat[i-k-1][j-k-1];                    
            }
        }
        
        return ans;
        
    }
};
