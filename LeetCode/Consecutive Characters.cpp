// Question Link - https://leetcode.com/problems/consecutive-characters/

// Solution - 

class Solution {
public:
    int maxPower(string s) {
        int n = s.length(), ans = 0, cnt = 1;
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1])
                cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
