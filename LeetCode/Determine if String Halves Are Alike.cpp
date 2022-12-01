// Question Link - https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Solution - 

class Solution {
public:
    int countVowels(string s){
        int cnt = 0;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                cnt += 1;
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        transform(begin(s), end(s), begin(s), ::tolower);
        int n = s.length();
        string first = s.substr(0, n/2), second = s.substr(n/2, n/2);
        return countVowels(first) == countVowels(second);
    }
};
