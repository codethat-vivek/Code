// Question Link - https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// Solution - 

class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int n = nums.size(), MOD = 1e9+7;
        int ans = 0;
        
        int power[n+1];
        power[0] = 1;
        for(int i=1; i<n+1; i++)
            power[i] = (power[i-1]*2)%MOD;
        
        
        for(int i=0; i<n; i++){
            int idx = upper_bound(nums.begin()+i, nums.end(), target-nums[i])-nums.begin();
            //cout << i << " " << target-nums[i] << " " << idx << "\n";
            if(idx == n)
                ans = (ans + power[n-i-1])%MOD;
            else if(idx == i){
                if (nums[i]+nums[idx] <= target)
                    ans = (ans + 1) % MOD;
            }
            else{
                if (nums[i] + nums[idx] <= target)
                    ans = (ans + power[idx-i])%MOD;
                else
                    ans = (ans + power[idx-i-1])%MOD;
            }
        }
        return ans;
    }
};
