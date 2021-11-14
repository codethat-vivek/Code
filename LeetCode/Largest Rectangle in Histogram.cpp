// Question Link - https://leetcode.com/problems/largest-rectangle-in-histogram/

// Solution - 

class Solution {
public:
    
    vector<int> nearestSmallerLeft(vector<int>heights){
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
    vector<int> nearestSmallerRight(vector<int>heights){
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
    
    int largestRectangleArea(vector<int>& heights) {
        // nearest smaller in left and right direction both
        int n = heights.size();
        vector<int>leftIdx = nearestSmallerLeft(heights);
        vector<int>rightIdx = nearestSmallerRight(heights);
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            ans = max(ans, (leftIdx[i]+rightIdx[i]-1)*heights[i]);

        return ans;
    }
};
