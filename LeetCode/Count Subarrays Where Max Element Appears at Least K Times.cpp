// Question Link - https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

// Solution - 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0, mx=0, lastcontribuition=0;
        for(int i : nums)
            mx = max(mx, i);
        
        long long ans = 0, cnt = 0;
        int mxCnt = 0;
        
        while(j < n){
            if(nums[j] == mx)
                mxCnt++;
            ans += cnt;
            if(mxCnt >= k){
                int x = 0;
                while(mxCnt >= k){
                    x++;
                    if(nums[i++] == mx)
                        mxCnt--;
                }
                ans += x;
                cnt += x;
            }
            j ++;
            
        }
        return ans;
        
    }
};
