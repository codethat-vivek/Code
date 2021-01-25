/*
  Question - 
  Given a number N, print all its unique prime factors and their powers in N.
  
  Example : 
    Input: N = 100
    Output: 2 2 5 2
    Explanation: 
    Factor Power
      2      2
      5      2
*/

// SOLUTION - 

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n){
    if(n < 2)return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
	
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    for(int i=2; i<=n; i++){
	        int cnt = 0;
	        int original = n;
	        while(isPrime(i) && original%i == 0){
	            cnt ++;
	            original = original/i;
	        }
	        if(cnt != 0)
	            cout << i << " " << cnt << " ";
	    }
	    cout << endl;
	}
	
	return 0;
}
