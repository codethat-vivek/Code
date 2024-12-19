// Question Link - https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

// Solution - 

#define pii pair<int, int>

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        
        while(k--){
            auto [ele, idx] = pq.top();
            pq.pop();
            nums[idx] = ele*multiplier;
            pq.push({nums[idx], idx});
        }
        
        return nums;
    }
};
