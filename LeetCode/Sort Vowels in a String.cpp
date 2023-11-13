// Question Link - https://leetcode.com/problems/sort-vowels-in-a-string/

// Solution - 

class Solution {
public:
    bool isVow(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        string vow = "";
        for(char c : s)
            if(isVow(c)) vow += c;
        
        sort(vow.begin(), vow.end());
        int i=0;
        for(char &c : s)
            if(isVow(c)) c = vow[i++];
        return s;
    }
};
