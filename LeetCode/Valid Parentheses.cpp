// Question Link - https://leetcode.com/problems/valid-parentheses/

// Solution Details - https://leetcode.com/submissions/detail/447727010/

// SOLUTION - 

class Solution {
public:
    
    bool validationFunction(char a, char b){
        if(a == '(' && b == ')')return true;
        if(a == '{' && b == '}')return true;
        if(a == '[' && b == ']')return true;
        return false;
    }
    
    bool isOpeningBracket(char a){
        if(a == '(' || a == '{' || a == '[')
            return true;
        return false;
    }
    
    bool isValid(string s) {
        stack <char> st;
        if(s[0] == ')' || s[0] == '}' || s[0] == ']')return false;
        for(int i=0; i<s.length(); i++){
            if(isOpeningBracket(s[i]))
                st.push(s[i]);
            else{
                if(st.empty())return false; // This was the line I was missing.
                if(!validationFunction(st.top(), s[i]))
                    return false;
                else
                    st.pop();
            }
        }
        if(st.size() == 0)return true;
        return false;
    }
};
