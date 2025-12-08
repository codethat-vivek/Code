// Question Link - https://leetcode.com/problems/count-square-sum-triples/

// Solution - 

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                float squareRoot = sqrt(i*i + j*j);
                if(int(squareRoot) == squareRoot && squareRoot <= n){
                    count += 2;
                }
            }
        }
        return count;
    }
};
