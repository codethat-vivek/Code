// Question Link - https://leetcode.com/problems/minimum-size-subarray-sum/

// Solution - 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0, j=0;
        int sm = 0;
        while(j < nums.size()){
            sm += nums[j++];
            while(sm >= target){
                ans = min(ans, j-i);
                sm -= nums[i++];
            }
        }
        
        if(ans == INT_MAX) return 0;
        return ans;
    }
};
