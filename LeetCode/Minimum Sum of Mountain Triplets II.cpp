// Question Link - https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/

// Solution - 

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), ans=INT_MAX;
        vector<int>prefMin(n), suffMin(n);
        prefMin[0] = nums[0]; suffMin[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
            prefMin[i] = min(prefMin[i-1], nums[i]);
        for(int i=n-2; i>=0; i--)
            suffMin[i] = min(suffMin[i+1], nums[i]);
        
        for(int i=1; i<n-1; i++){
            if(nums[i] > prefMin[i-1] && nums[i] > suffMin[i+1])
                ans = min(ans, prefMin[i-1] + nums[i] + suffMin[i+1]);        
        }
        
        return ans != INT_MAX ? ans : -1;
        
    }
};
