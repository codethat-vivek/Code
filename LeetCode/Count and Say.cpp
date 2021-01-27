// Question Link - https://leetcode.com/problems/count-and-say/

// Solution Details - https://leetcode.com/submissions/detail/448541775/

// SOLUTION - 

class Solution {
public:
   
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = "";
        string num = countAndSay(n-1);
        int cnt = 1;
        int i;
        for(i=0; i<num.length()-1; i++){
            if(num[i] == num[i+1])
                cnt++;
            else{
                s += to_string(cnt);
                s += num[i];
                cnt = 1;
            }
        }

        s += to_string(cnt);
        s += num[i];
        
        return s;

        
    }
};
