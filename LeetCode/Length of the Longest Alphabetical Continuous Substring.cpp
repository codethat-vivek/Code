// Question Link - https://leetcode.com/contest/weekly-contest-311/problems/length-of-the-longest-alphabetical-continuous-substring/

// Solution - 

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        if(n == 1) return 1;
        
        int i=0, j=1;
        int ans = 1;
        while(j < n){
            while(s[j] - s[j-1] == 1)
                j++;
            ans = max(ans, j-i);
            i = j;
            j += 1;
        }
        ans = max(ans, j-i);
        return ans;
    }
};
