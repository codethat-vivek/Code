// Question Link - https://leetcode.com/problems/trapping-rain-water/

// Solution - 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxInLeft, maxInRight(n);
        int mx = -1;
        for(int i=0; i<n; i++){
            if(mx == -1)
                maxInLeft.push_back(height[i]);
            else
                maxInLeft.push_back(mx);
            mx = max(mx, height[i]);
        }
        mx = -1;
        for(int i=n-1; i>=0; i--){
            if(mx == -1)
                maxInRight[i] = height[i];
            else
                maxInRight[i] = mx;
            mx = max(mx, height[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int mn = min(maxInLeft[i], maxInRight[i]);
            if(mn > height[i])
                ans += (mn - height[i]);
        }
        return ans;
        
    }
};
