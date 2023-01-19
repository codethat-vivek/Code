// Question Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Solution - 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int r, subarrays = 0, n = nums.size();
        unordered_map<int, int>um; um[0] = 1;
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1]+nums[i];
        for(int i=0; i<n; i++){
            r = prefix[i]%k;
            if(r < 0)r += k;
            if(um.find(r) == um.end())
                um[r] = 1;
            else{
                subarrays += um[r];
                um[r] += 1;
            }
        }
        return subarrays;
    }
};
