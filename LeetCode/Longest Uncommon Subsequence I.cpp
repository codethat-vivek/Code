// Question Link - https://leetcode.com/problems/longest-uncommon-subsequence-i/

// Solution - 

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        return max(a.size(), b.size());
    }
};
