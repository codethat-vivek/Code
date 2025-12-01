// Question Link - https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/description/

// Solution - 

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int ub = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            if(n-ub >= k)
                ans ++;
        }
        
        return ans;
    }
};
