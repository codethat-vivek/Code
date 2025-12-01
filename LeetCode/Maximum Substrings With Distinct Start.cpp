// Question Link - https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

// Solution - 

class Solution {
public:
    int maxDistinct(string s) {
        int n = s.length(), ans = 0;
        set<char>st;
        for(char c : s){
            if(st.find(c) == st.end())
                ans++;
            st.insert(c);
        }

        return ans;

    }
};
