// Question Link - https://leetcode.com/problems/transpose-matrix/

// Solution - 

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> result(cols, vector<int>(rows, 0));
        int m=0, n=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                result[m][n] = matrix[i][j];
                m += 1;
                if(m == cols){
                    m = 0;
                    n += 1;
                }
            }
        }
        return result;
    }
};
