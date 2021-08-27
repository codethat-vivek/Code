// Question Link - https://leetcode.com/problems/longest-uncommon-subsequence-ii/

// Solution - 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // true if s is subsequence of t
        
        int sub = s.length();
        int big = t.length();
        int i=0, j=0;
        while(i<sub && j<big){
            if(s[i] == t[j])
                i++;
            j++;
        }
        if(i == sub)
            return true;
        return false;
        
    }
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, int>um;
        for(auto each : strs)
            um[each]++;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(um[strs[i]] == 1){
                int j;
                for(j=0; j<n; j++){
                    if(i == j)
                        continue;
                    if(isSubsequence(strs[i], strs[j]))
                        break;
                }
                if(j == n)
                    ans = max(ans, (int)strs[i].size());
            }
        }
        if(ans == INT_MIN)
            return -1;
        return ans;
    }
};
