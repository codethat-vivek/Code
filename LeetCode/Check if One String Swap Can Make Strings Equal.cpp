// Question Link - https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

// Solution - 

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if(s1 == s2) return true;
        int diff = 0;
        char fa, fb, sa, sb;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                if(diff == 0){
                    fa = s1[i]; sa = s2[i];
                }
                else{
                    fb = s1[i]; sb = s2[i];
                }
                diff++;
            }
                
        }
        if(diff != 2) return false;
        //cout << fa << " " << fb << " " << sa << " " << sb << endl;
        return fa == sb && sa == fb;

    }
};
