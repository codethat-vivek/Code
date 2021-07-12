// Question Link - https://leetcode.com/problems/house-robber/

// Solution - 

class Solution {
public:
    int rob(vector<int>& nums) {
        int pre_max_pos;
        int pre_max;
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        vector<int>arr(n, 0);
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            if(arr[i-2] >= arr[i-1])
                arr[i] = nums[i]+arr[i-2];
            else
                arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
        }
        return arr[n-1];
    }
};
