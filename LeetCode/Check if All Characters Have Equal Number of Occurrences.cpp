// Question Link - https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

// Solution - 

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int>um;
        for(char c : s)
            um[c]++;
        int k = um[s[0]];
        for(char c : s){
            if(um[c] != k)
                return false;
        }
        return true;
    }
};
