// Question Link - https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/

// Solution - 

class Solution {
public:

    long long fact(int n, int &MOD){
        long long ans = 1;
        for(int i=n; i>=2; i--){
            ans = (ans * i) % MOD;
        }
        return ans % MOD;
    }

    int countPermutations(vector<int>& complexity) {
        int count = 0, n = complexity.size(), MOD = 1e9+7;
        for(int i=1; i<n; i++){
            if(complexity[i] > complexity[0])
                count++;
        }
        if(count != n-1) return 0;
        return fact(count, MOD);
    }
};
