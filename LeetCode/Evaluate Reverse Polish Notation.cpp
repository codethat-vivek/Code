// Question Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Solution - 

class Solution {
public:
    bool isOperator(string s){
        if(s == "+" || s == "-" || s == "*" || s == "/")return true;
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(string t : tokens){
            if(!isOperator(t))st.push(t);
            else{
                int ele2 = stoi(st.top());
                st.pop();
                int ele1 = stoi(st.top());
                st.pop();
                int ans;
                if(t == "+")
                    ans = ele1 + ele2;
                
                else if(t == "-")
                    ans = ele1 - ele2;
                
                else if(t == "*")
                    ans = ele1 * ele2;
                
                else
                    ans = ele1 / ele2;
                
                st.push(to_string(ans));
                
            }
        }
        return stoi(st.top());
    }
};
