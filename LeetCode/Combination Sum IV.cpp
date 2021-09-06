// Question Link - https://leetcode.com/problems/combination-sum-iv/

// Solution - 

class Solution {
public:
    std::vector<int> dp = std::vector<int>(10001, -1);
    int helper(vector<int>nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[target] != -1)
            return dp[target];
        int x = 0;
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            x += helper(nums, rem);
        }
        dp[target] = x;
        return x;
            
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        return helper(nums, target);
    }
};
