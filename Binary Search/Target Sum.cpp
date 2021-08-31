// Question Link - https://leetcode.com/problems/target-sum/

// Solution - 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        Let subarray1 be the first subarray and subarray2 be the second subarray
	    subarray1 + subarray2 = sum ------------------- (i)
	    subarray1 - subarray2 = target ------------------(ii)
	
	    (i)+(ii)
	    => 2*subarray1 = sum + target
	    => subarray1 = (sum + target)/2
	    => subarray2 = (sum - target)/2
	    Therefore we need to find count of subsets with sum (sum-target)/2 in the nums array
        */
        int n = nums.size();
        int sm = 0, cnt = 0;
        for(auto x : nums)
            sm += x;
        if(target > sm || (sm-target)%2 != 0)
            return 0;
        int newTarget = (sm-target)/2;
        vector<vector<int>>dp(n+1, vector<int>(newTarget+1, 0));
        dp[0][0] = 1;
        // Since there nums[i] can be zero, therefore we need to initialise more the dp array more carefully
        for(int i=1; i<n+1; i++){
            if(nums[i-1] == 0)cnt++;
            dp[i][0] = pow(2, cnt);
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<newTarget+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][newTarget];
    }
};
