// Question Link - https://leetcode.com/problems/count-special-triplets/

// Solution - 

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        map<int, long long> fmp, mp;

        for (int e : nums)
            fmp[e]++;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long x = nums[i];
            long long target = 2 * x;

            if (mp.count(target)) {
                long long left = mp[target];
                long long right = fmp[target] - mp[target];

                if (x == 0) {
                    right--;
                }

                if (right > 0) {
                    ans = (ans + (left % MOD) * (right % MOD)) % MOD;
                }
            }

            mp[x]++;
        }

        return (int)(ans % MOD);
    }
};
