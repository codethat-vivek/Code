// Question Link - https://leetcode.com/problems/maximal-rectangle/

// Solution - 

class Solution {
public:
    
   vector<int> nearestSmallerToLeft(vector<int>heights){
        int n = heights.size();
        stack<pair<int, int>>st;
        vector<int>idx;
        for(int i=0; i<n; i++){
            if(st.empty())
                idx.push_back(-1);
            else if(st.top().first < heights[i])
                idx.push_back(st.top().second);
            else{
                while(!st.empty() && st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                    idx.push_back(-1);
                else
                    idx.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        for(int i=0; i<idx.size(); i++)
            idx[i] = i-idx[i];
        return idx;
    }
    vector<int> nearestSmallerToRight(vector<int>heights){
        int n = heights.size();
        stack<pair<int, int>>st;
        vector<int>idx;
        for(int i=n-1; i>=0; i--){
            if(st.empty())
                idx.push_back(-1);
            else if(st.top().first < heights[i])
                idx.push_back(st.top().second);
            else{
                while(!st.empty() && st.top().first >= heights[i])
                    st.pop();
                if(st.empty())
                    idx.push_back(-1);
                else
                    idx.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        
        reverse(idx.begin(), idx.end());
        for(int i=0; i<n; i++){
            if(idx[i] == -1)
                idx[i] = n-i;
            else
                idx[i] = idx[i]-i;
        }
        return idx;
    }
    
    int maximumAreaHistogram(vector<int>& heights) {
        // nearest smaller in left and right direction both
        int n = heights.size();
        vector<int>leftIdx = nearestSmallerToLeft(heights);
        vector<int>rightIdx = nearestSmallerToRight(heights);
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            ans = max(ans, (leftIdx[i]+rightIdx[i]-1)*heights[i]);

        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = 0, idx = 0;
        vector<vector<int>>grid;
        for(int i=0; i<rows; i++){
            grid.push_back({});
            for(int j=0; j<cols; j++)
                grid[i].push_back(matrix[i][j] - '0');
            
        }
        for(int j=0; j<cols; j++){
            for(int i=1; i<rows; i++){
                if(grid[i][j] == 1)
                    grid[i][j] += grid[i-1][j];
            }
        }
        
        for(int i=0; i<rows; i++)
            ans = max(ans, maximumAreaHistogram(grid[i]));
        return ans;
    }
};
