// Question Link - https://leetcode.com/problems/palindrome-number/

// Solution Link - https://leetcode.com/submissions/detail/443809060/

// SOLUTION - 

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string ans = "";
        for(int i=s.length()-1; i>=0; i--){
            ans += s[i];
        }
        if (s == ans)
            return true;
        else
            return false;
    }
};
