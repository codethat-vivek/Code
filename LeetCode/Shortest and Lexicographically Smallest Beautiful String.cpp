// Question Link - https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

// Solution - 

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, j=0, cnt=0, n=s.length();
        string ans = "";
        while(j < n){
            if(s[j] == '1')
                cnt++;
            while(cnt > k){
                if(s[i] == '1')
                    cnt -= 1;
                i++;
            }
            if(cnt == k){
                while(s[i] == '0')
                    i ++;
                string t = s.substr(i, j-i+1);
                if(ans == "")
                    ans = t;
                else{
                    if(ans.length() > j-i+1)
                        ans = t;
                    else if(ans.length() == j-i+1)
                        ans = min(ans, t);
                }
            }
            j ++;
        }
        return ans;
    }
};
