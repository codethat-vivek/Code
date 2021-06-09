/*
  Question - Mysterious Series
  Find the Nth term of the Mysterious series.
  N    Nth term
  1    5
  2    10
  3    26
  4    50
  5    122
  .
  .
  .
  10    842
  
  Expected Time Complexity: O(nlogn)
  Expected Auxiliary Space: O(n)
  
  Constraints:
  1 <= N <= 1000
*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isPrime(int n){
        if(n<2)return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    
    int primeGenerator(int n){
        int i;
        for(i=2; i<7920; i++){
            if(isPrime(i))n--;
            if(n == 0)break;
        }
        return i;
    }
    
    long long nthMysterious(long long N){
        // code here
        int x = primeGenerator(N);
        return (x*x+1);
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.nthMysterious(N) << endl;
    }
    return 0;
}
