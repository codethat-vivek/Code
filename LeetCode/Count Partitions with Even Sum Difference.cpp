// Question Link - https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

// Solution - 

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sm = 0;
        int n = nums.size();
        for(int x : nums) sm += x;
        int ans = 0, curr = 0;
        for(int x : nums){
            curr += x;
            if(abs(sm - 2 * curr) % 2 == 0)
                ans ++;
        }
        return ans == n ? ans - 1 : ans;
    }
};
