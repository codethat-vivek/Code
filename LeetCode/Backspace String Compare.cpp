// Question Link - https://leetcode.com/problems/backspace-string-compare/

// Solution - 

class Solution {
public:
    string helper(string s){
        stack<char>st;
        string ans = "";
        for(char c : s){
            if(c != '#')
                st.push(c);
            else{
                if(st.empty()) continue;
                st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string a = helper(s), b = helper(t);
        return a == b;
    }
};
