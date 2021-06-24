// Question Link - https://leetcode.com/problems/make-the-string-great/

// Solution - 

class Solution {
public:
    string makeGood(string s) {
        for(int i=0; i<s.length(); i++){
            if(abs(s[i] - s[i+1]) == 32){
                s = s.substr(0,i) + s.substr(i+2);
                i-=2;
            }
            if(i < 0)
                i = -1;
        }
        return s;
    }
};
