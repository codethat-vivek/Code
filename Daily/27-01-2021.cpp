/*
Question - Least Prime Factor
You dont need to read input or print anything. Complete the function leastPrimeFactor() which takes N as input parameter and 
returns a list of integers containing all the least prime factor of each numbers from 1 to N.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)
Constraints: 2<= n <=10^3
For Example: 
Input: N = 6
Output: [1, 2, 3, 2, 5, 2] 

*/

// SOLUTION - 

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;



// User function Template for C++
class Solution {
  public:
  
    bool isPrime(int n){
        if (n<2)return false;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
                return false;
        }
        return true;
    }
    
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>v;
        v.push_back(0);
        for(int i=1; i<=n; i++){
            if(i == 1)
                v.push_back(1);
            else if(i%2 == 0)
                v.push_back(2);
            else if(i%2 != 0){
                for(int j=3; j<=i; j+=2){
                    if(i%j == 0 && isPrime(j)){
                        v.push_back(j);
                        break;
                    }
                }
            }
        }
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}
