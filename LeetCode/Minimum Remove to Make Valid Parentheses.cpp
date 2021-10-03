// Question Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

// Solution - 

class Solution {
public:

    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n = s.length();
        string ans = "";
        vector<char>v(n, '#');
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] >= 97 && s[i] <= 122)
                v[i] = s[i];
            else if(s[i] == ')'){
                if(!st.empty()){
                    v[(int)st.top()] = '(';
                    v[i] = s[i];
                    st.pop();
                }
            }
        }

        for(int i=0; i<n; i++){
            if(v[i] != '#')
                ans += v[i];
        }
    
        return ans;
        
    }
};
