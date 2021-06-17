// Question Link - https://leetcode.com/problems/running-sum-of-1d-array/

// Solution - 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int s = 0;
        for(int i=0; i<nums.size(); i++)
        {
            s += nums[i];
            nums[i] = s;
        }
        return nums;
    }
};
