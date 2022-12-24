// Question Link - https://leetcode.com/problems/domino-and-tromino-tiling/

// Solution - 

class Solution {
public:
    int MOD = 1e9+7;
    int numTilings(int n) {
        int arr[1001];
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 5;
        for(int i=4; i<=n; i++)
            arr[i] = ((arr[i-1]+arr[i-3])%MOD+arr[i-1])%MOD;
        return arr[n];
    }
};
