// Question Link - https://leetcode.com/problems/two-best-non-overlapping-events/

// Solution - 

class Solution {
public:
    
    int kBestEvents(int idx, int jobs, int k, vector<vector<int>>& events, vector<vector<int>> &dp){
        if(idx == events.size() || jobs == k)
            return 0;
        if(dp[idx][jobs] != -1)
            return dp[idx][jobs];
        
        vector<int>vec = {events[idx][1], INT_MAX, INT_MAX};
        int newIdx = upper_bound(events.begin(), events.end(), vec) - events.begin();
        int val1 = events[idx][2] + kBestEvents(newIdx, jobs+1, k, events, dp);
        
        int val2 = kBestEvents(idx+1, jobs, k, events, dp);
        
        return dp[idx][jobs] = max(val1, val2);
        
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int k = 2;
        vector<vector<int>>dp(n, vector<int>(k, -1));
        return kBestEvents(0, 0, k, events, dp);
    }
};
