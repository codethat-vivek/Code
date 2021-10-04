// Question Link - https://leetcode.com/problems/island-perimeter/

// Solution - 

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int n = 0;
                if(grid[i][j] == 1){
                    if(i+1 < rows && grid[i+1][j] == 1)
                        n++;
                    if(i-1 >=0 && grid[i-1][j] == 1)
                        n++;
                    if(j+1 < cols && grid[i][j+1] == 1)
                        n++;
                    if(j-1 >= 0 && grid[i][j-1] == 1)
                        n++;
                    perimeter += (4-n);
                }
            }
        }
        return perimeter;
    }
};
