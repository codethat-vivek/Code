// Question Link - https://leetcode.com/problems/flip-string-to-monotone-increasing/

// Solution - 

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zero[n], ones[n];
        int total_zeroes = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                total_zeroes++;
        }
        if(s[0] == '0'){
            zero[0] = 1;
            ones[0] = 0;
        }
        else{
            ones[0] = 1;
            zero[0] = 0;
        }
        for(int i=1; i<n; i++){
            if(s[i] == '0'){
                zero[i] = zero[i-1] + 1;
                ones[i] = ones[i-1];
            }
            else{
                ones[i] = ones[i-1] + 1;
                zero[i] = zero[i-1];
            }
        }
        
        // for(int i=0; i<n; i++)
        //     cout << zero[i] << " ";
        // cout << "\n";
        // for(int i=0; i<n; i++)
        //     cout << ones[i] << " ";
        // cout << "\n";
        
        int ans = min(n, total_zeroes);
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                ans = min(ans, ones[i]+total_zeroes-zero[i]);
            else
                ans = min(ans, ones[i]+total_zeroes-zero[i]);
        }
        return ans;
    }
};
