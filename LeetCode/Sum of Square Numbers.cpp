// Question Link - https://leetcode.com/problems/sum-of-square-numbers/

// Solution - 

class Solution {
public:
    bool isSquare(int n){
        if(sqrt(n) == int(sqrt(n)))
            return true;
        return false;
    }
    bool judgeSquareSum(int c) {
        for(int i=0; i<=int(sqrt(c/2)); i++){
            if(isSquare(c-i*i))
                return true;
        }
        return false;
    }
};
