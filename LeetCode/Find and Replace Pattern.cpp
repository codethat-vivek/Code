// Question Link - https://leetcode.com/problems/find-and-replace-pattern/

// Solution - 

class Solution {
public:
    bool isValid(string word, string pattern){
        map<char, char>m1;
        map<char, char>m2;
        int n = word.length(); // assuming word's length and pattern's length to be same
        for(int i=0; i<n; i++){
            if(m1.find(pattern[i]) == m1.end() && m2.find(word[i]) == m2.end()){
                m1[pattern[i]] = word[i];
                m2[word[i]] = pattern[i];
            }
            else if(m1[pattern[i]]  !=  word[i] || m2[word[i]] != pattern[i])
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int fixedLength = pattern.length();
        vector<string>ans;
        for(string word : words){
            if(word.length() != fixedLength)
                continue;
            if(isValid(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }
};
