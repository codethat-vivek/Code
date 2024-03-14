// Question Link - https://leetcode.com/problems/binary-subarrays-with-sum/

// Solution - 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size(), sm = 0, ans = 0;
        unordered_map<int, int>um;
        um[0] = 1;
        for(int i=0; i<n; i++){
            sm += nums[i];
            ans += um[sm-goal];
            um[sm] += 1;
            
        }
        return ans;
    }
};
