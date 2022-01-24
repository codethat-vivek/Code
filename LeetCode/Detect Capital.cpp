// Question Link - https://leetcode.com/problems/detect-capital/

// Solution - 

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cntBig=0, cntSmall=0;
        int n = word.length();
        for(int i=0; i<n; i++){
            if(65 <= word[i] && word[i] <= 90)cntBig++;
            else if(97 <= word[i] && word[i] <= 122)cntSmall++;
        }
        if(cntBig == n || cntSmall == n)return true;
        if(cntBig == 1 && 65 <= word[0] && word[0] <= 90)return true;
        return false;
    }
};
