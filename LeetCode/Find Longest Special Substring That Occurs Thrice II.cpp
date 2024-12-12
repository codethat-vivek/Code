// Question Link - https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/

// Solution - 

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(), ans = -1, i = 0, j = 0;
        unordered_map<string, int>um;
        string t = "";
        while(j < n){
            if(s[i] == s[j])
                t += s[j];
            else{
                int len = j-i, cnt = 1;
                while(len != 0){
                    um[t] += cnt++;
                    t.pop_back();
                    len --;
                }
                i = j;
                t = s[i];
            }
            j += 1;
        }
        int len = j-i, cnt = 1;
        while(len != 0){
            um[t] += cnt++;
            t.pop_back();
            len --;
        }
        for(auto &x : um){
            int len = (int)x.first.length(), cnt = x.second;
            // cout << x.first << " " << cnt << endl;
            if(cnt >= 3) ans = max(ans, len);
            // else ans = max(ans, len-2);
        } 
        
        return ans;
    }
};
