/* 
Question - Product of Primes
Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 109+7. 
If there are no primes in that range you must print 1.

Example 1:

Input: L = 1, R = 10
Output: 210
Explaination: The prime numbers are 
2, 3, 5 and 7.

*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long x = pow(10, 9) + 7;
    bool isPrime(long long n){
        if(n == 1)
            return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
    long long primeProduct(long long L, long long R){
        // code here
        long long product = 1;
        for(long long i = L; i <= R; i++){
            if(isPrime(i)){
                product *= i;
                product = product % x;
            }
        }
        return product;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
