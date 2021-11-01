// Question Link - https://www.codechef.com/problems/FLOW018

// SOLUTION -

#include <iostream>
using namespace std;

int fibo(int n){
    if(n == 0)
        return 1;
    else
        return fibo(n-1)*n;
        
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
        cin >> n;
	    cout << fibo(n) << endl;
	}
	return 0;
}
