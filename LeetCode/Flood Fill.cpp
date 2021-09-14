// Question Link - https://leetcode.com/problems/flood-fill/

// Solution - 

class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int val, int newColor){
        int rows = image.size();
        int cols = image[0].size();
        
        image[i][j] = newColor;
        if(i+1 >= 0 && j >= 0 && i+1 < rows && j < cols && image[i+1][j] == val)
            dfs(image, i+1, j, val, newColor);
        if(i-1 >= 0 && j >= 0 && i-1 < rows && j < cols && image[i-1][j] == val)
            dfs(image, i-1, j, val, newColor);
        if(i >= 0 && j+1 >= 0 && i < rows && j+1 < cols && image[i][j+1] == val)
            dfs(image, i, j+1, val, newColor);
        if(i >= 0 && j-1 >= 0 && i < rows && j-1 < cols && image[i][j-1] == val)
            dfs(image, i, j-1, val, newColor);
        return;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {       if(image[sr][sc] == newColor)
            return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;       
    }
};
