// Question Link - https://leetcode.com/problems/is-subsequence/submissions/

// Solution - 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // true if s is subsequence of t
        
        int sub = s.length();
        int big = t.length();
        int i=0, j=0;
        while(i<sub && j<big){
            if(s[i] == t[j])
                i++;
            j++;
        }
        if(i == sub)
            return true;
        return false;
        
    }
};
