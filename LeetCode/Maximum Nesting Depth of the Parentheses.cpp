// Question Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// Solution - 

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
