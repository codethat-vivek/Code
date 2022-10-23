// Question Link - https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/

// Solution - 

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int hcf;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % k == 0){
                hcf = nums[i];
                if(hcf == k) ans++;
                for(int j=i+1; j<n; j++){
                    hcf = __gcd(hcf, nums[j]);
                    if(hcf % k != 0) break;
                    if(hcf == k)ans++;
                }
            }
        }
        return ans;
    }
};
