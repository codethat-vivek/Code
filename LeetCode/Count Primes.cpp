// Question Link - https://leetcode.com/problems/count-primes/

// Solution - 

class Solution {
public:
    int countPrimes(int n) {
        vector<int>primes(n, 1);
        for(int i=2; i*i<n; i++){
            if(primes[i]){
                for(int j=i; j*i<n; j++){
                    primes[i*j] = 0;
                }
            }
        }
        int ans = 0;
        for(int i=2; i<n; i++){
            if(primes[i])
                ans++;
        }
        return ans;
    }
};
