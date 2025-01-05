// Question Link - https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05

// Solution - 

class Solution {
public:

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>diff(n+1, 0);
        for(auto &sh : shifts){
            if(sh[2] == 1){
                diff[sh[0]] ++;
                diff[sh[1]+1] --;
            }
            else{
                diff[sh[0]] --;
                diff[sh[1]+1] ++;
            }
        }
        string ans = "";
        int incr = 0;
        for(int i=0; i<n; i++){
            // cout << diff[i] << " ";
            incr += diff[i];
            incr = incr%26;
            ans += ((s[i]-'a'+incr+26)%26 + 'a');
        }

        return ans;
    }
};
