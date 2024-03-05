// Question Link - https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// Solution - 

class Solution {
public:
    // RECURSION - not working due to memory limit exceeded

    // int helper(string s, int n, int i, int j){
    //     if(i >= j || s[i] != s[j]) 
    //         return 0;
    //     int cnt = 2;
    //     while(i+1 < j && s[i] == s[i+1]){
    //         i++;
    //         cnt++;
    //     }
    //     while(i < j-1 && s[j] == s[j-1]){
    //         j--;
    //         cnt++;
    //     }
    //      //cout << cnt << " " << i << " " << j << endl;
    //     return cnt + helper(s, n, i+1, j-1);
    // }
    
    int minimumLength(string s) {
        int n = s.length();
        //return n - helper(s, n, 0, n-1);
        int i=0, j=n-1, cnt=0, ans=n;
        while(i < j && s[i] == s[j]){
            int x=i, y=j, cnt=2;
            while(x+1 < y && s[x] == s[x+1]){
                x++;
                cnt++;
            }
            while(x < y-1 && s[y] == s[y-1]){
                y--;
                cnt++;
            }
            //cout << cnt << " " << i << " " << j << "\n";
            i = ++x;
            j = --y;
            ans -= cnt;
        }
        return ans;
    }
};
