// Question Link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// Solution - 

class Solution {
public:
    int minPartitions(string n) {
        int mx = -2;
        for(char c : n){
            mx = max(mx, c-'0');
        }
        return mx;
    }
};
