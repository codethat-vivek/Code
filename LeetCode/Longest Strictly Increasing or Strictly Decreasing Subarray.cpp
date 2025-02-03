// Question Link - https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

// Solution - 

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longest = 1, inc = 1, dec = 1;
        for(int i=0; i<n-1; i++){
            longest = max(longest, max(inc, dec));
            if(nums[i] < nums[i+1]){
                inc++;
                dec = 1;
            }
            else if(nums[i] > nums[i+1]){
                dec++;
                inc = 1;
            }
            else{
                longest = max(longest, max(inc, dec));
                inc = 1;
                dec = 1;
            }
        }
        longest = max(longest, max(inc, dec));
        return longest;
    }
};
