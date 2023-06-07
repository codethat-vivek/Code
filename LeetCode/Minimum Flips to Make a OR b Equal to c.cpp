// Question Link - https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// Solution - 

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0, x, bitA, bitB, bitC;
        for(int i=0; i<32; i++){
            x = 1<<i;
            bitA = a&x; bitB = b&x, bitC = c&x;
            if(bitC){
                if(!bitA && !bitB)
                    flips++;
            }
            else{
                if(bitA)flips++;
                if(bitB)flips++;
            }
        }
        return flips;
    }
};
