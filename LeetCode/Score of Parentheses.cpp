// Question Link - https://leetcode.com/problems/score-of-parentheses/

// Solution - 

class Solution {
public:
    vector<int> v = std::vector<int>(51);
    int findScore(int start, int high){
        int endPos = v[start];
        if(start + 1 == high)
            return 1;
        if(endPos == high)
            return 2*findScore(start+1, high-1);
        return findScore(start, endPos) + findScore(endPos+1, high);
    }
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                v[st.top()] = i;
                st.pop();
            }
            else
                st.push(i);
        }
        return findScore(0, n-1);
    }
};
