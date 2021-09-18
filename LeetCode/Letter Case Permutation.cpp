// Question Link - https://leetcode.com/problems/letter-case-permutation/

// Solution - 

class Solution {
public:
    vector<string>ans;
    void helper(string s, int i, int n){
        if(i == n){
            ans.push_back(s);
            return;
        }
        if(s[i] >= 48 && s[i] <= 57)
            helper(s, i+1, n);
        else if(s[i] >=65 && s[i] <= 90){ // for capital case letters
            helper(s, i+1, n);
            s[i] = char(s[i]+32); // changing capital to small case
            helper(s, i+1, n);
            s[i] = char(s[i]-32); // changing it back 
        }
        else if(s[i] >= 97 && s[i] <= 122){ // for small case letters
            helper(s, i+1, n);
            s[i] = char(s[i]-32);
            helper(s, i+1, n);
            s[i] = char(s[i]+32);
        }
        
        return;
        
    }
    vector<string> letterCasePermutation(string s) {
        helper(s, 0, s.length());
        return ans;
    }
};
