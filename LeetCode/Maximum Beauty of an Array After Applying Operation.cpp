// Question Link - https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

// Solution - 

class Solution {
public:
    // SWEEP LINE ALGORITHM
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int>um;
        for(int i : nums){
            um[i-k] += 1;
            um[i+k+1] -= 1;
        }
        
        vector<pair<int, int>>vp(um.begin(), um.end());
        sort(begin(vp), end(vp));
        
        int cnt = 0;
        for(pair<int, int> p : vp){
            cnt += p.second;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};
