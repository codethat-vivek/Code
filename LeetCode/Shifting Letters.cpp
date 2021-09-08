// Question Link - https://leetcode.com/problems/shifting-letters/

// Solution - 

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for(int i=n-2; i>=0; i--)
            shifts[i] = (shifts[i]+shifts[i+1])%26;
        for(int i=0; i<n; i++)
            s[i] = char((s[i]-97+shifts[i])%26+97);
        
        return s;
    }
};
