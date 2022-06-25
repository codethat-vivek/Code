// Question Link - https://leetcode.com/problems/maximum-sum-circular-subarray/

// Solution - 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sub_best = 0, best = 0;
        for(int i : nums){
            sub_best = max(i, sub_best + i);
            best = max(best, sub_best);
        }
        return best;
    }
    int minSubArray(vector<int>& nums) {
        int sub_best = 1e9+7, best = 1e9+7;
        for(int i : nums){
            sub_best = min(i, sub_best + i);
            best = min(best, sub_best);
        }
        return best;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        bool pos = false;
        int mx = -1e9+7;
        for(int i : nums){
            if(i > 0)
                pos = true;
            mx = max(mx, i);
        }
        if(!pos)
            return mx;
        int n = nums.size();
        int best = maxSubArray(nums);
        int sm = 0;
        for(int i : nums)sm += i;
        best = max(best, sm-minSubArray(nums));
        return best;
    }
};
