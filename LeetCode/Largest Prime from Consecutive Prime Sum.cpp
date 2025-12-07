// Question Link - https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/

// Solution - 

class Solution {
public:

    vector<int> getPrimes(int n){
        vector<int>numbers(n+1, 1), primes;
        for(int i=2; i<n+1; i++){ 
            if(numbers[i]){
                if(i == 2)
                    primes.push_back(i);
                else if(primes[primes.size()-1] + i <= n)
                    primes.push_back(primes[primes.size()-1] + i);
                else if(primes[primes.size()-1] + i > n)
                    return primes;
            }
                
            if(numbers[i] == 0)
                continue;
            int j=2; 
            while(i*j <= n){
                numbers[i*j] = 0;
                j++;
            }
        }

        return primes;
    }

    bool isPrime(int n){
        if(n == 2) 
            return true;
        for(int i=2; i<=int(sqrt(n)) + 1; i++){
            if(n % i == 0) return false;
        }

        return true;
    }

    int largestPrime(int n) {

        vector<int>primes = getPrimes(n);

        for(int i=primes.size()-1; i>=0; i--)
            if(isPrime(primes[i])) return primes[i];

        return 0;

    }
};
