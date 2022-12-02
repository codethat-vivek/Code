// Question Link - https://leetcode.com/problems/determine-if-two-strings-are-close/

// Solution - 

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>f1(26, 0), f2(26, 0);
        for(char c : word1)
            f1[c-'a']++;
        for(char c : word2)
            f2[c-'a']++;
        
        string f="", s="";
        
        for(int i=0; i<26; i++){
            if(f1[i] != 0 && f2[i] == 0) return false;
            if(f2[i] != 0 && f1[i] == 0) return false;
            if(f1[i] != 0 && f2[i] != 0){
                f += to_string(f1[i]);
                s += to_string(f2[i]);
            }
        }
        
        sort(begin(f), end(f));
        sort(begin(s), end(s));
        return f == s;
    }
};
