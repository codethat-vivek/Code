// Question Link - https://leetcode.com/problems/count-number-of-homogenous-substrings/

// Solution - 

class Solution {
public:
    int countHomogenous(string s) {
        long long int ans = 0, mod = 1e9+7, n = s.length();
        long long int cnt = 1;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1])
                cnt++;
            else{
                ans = (ans + (cnt*(cnt+1))/2) % mod;
                cnt = 1;
            }
        }
        ans = (ans + (cnt*(cnt+1))/2) % mod;
        return ans;
    }
};
