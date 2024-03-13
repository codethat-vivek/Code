// Question Link - https://leetcode.com/problems/find-the-pivot-integer/

// Solution - 

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n*(n+1))/2, sm = 0;
        for(int i=1; i<=n; i++){
            sm += i;
            if(2*sm == sum+i)
                return i;
        }
        return -1;
    }
};
