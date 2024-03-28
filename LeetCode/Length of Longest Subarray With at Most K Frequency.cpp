// Question Link - https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

// Solution - 

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>um;
        int ans = 0, i = 0, j = 0, cnt = 0;
        while(j < n){
            um[nums[j]] ++;
            if(um[nums[j]] > k){
                ans = max(ans, j-i);
                while(um[nums[j]] > k){
                    um[nums[i++]]--;
                }
            }
            else
                ans = max(ans, j-i+1);
            j ++;
        }
        return ans;
    }
};
