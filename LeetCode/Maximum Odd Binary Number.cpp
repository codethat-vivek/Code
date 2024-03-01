// Question Link - https://leetcode.com/problems/maximum-odd-binary-number/

// Solution - 

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(int i=0; i<s.length(); i++)
            if(s[i] == '1') ones++;
        int zeroes = s.length() - ones;
        string ans = "1"; ones--;
        while(zeroes--)
            ans += '0';
        while(ones--)
            ans += '1';
        reverse(begin(ans), end(ans));
        return ans;
    }
};
