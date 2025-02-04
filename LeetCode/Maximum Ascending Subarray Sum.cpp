// Question Link - https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

// Solution - 

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], curr = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1])
                curr += nums[i];
            else{
                ans = max(ans, curr);
                curr = nums[i];
            }
        }
        return max(ans, curr);
    }
};
