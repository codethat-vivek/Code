// Question Link - https://leetcode.com/problems/flip-string-to-monotone-increasing/

// Solution - 

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int total_zeroes = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                total_zeroes++;
        }
        int ones = 0, zeroes = 0;
        int ans = min(n, total_zeroes);
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                zeroes++;
            else
                ones++;
            ans = min(ans, ones+total_zeroes-zeroes);
        }
        return ans;
    }
};
