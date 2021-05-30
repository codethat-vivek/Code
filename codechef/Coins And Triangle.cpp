// Question Link - https://www.codechef.com/problems/TRICOIN

// Solution Link - https://www.codechef.com/viewsolution/36868013

// Solution - 

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	long long n, k, i;
	while(t--){
	    cin >> n;
	    k = (int)sqrt(2*n);
	    
	    for(i=k; i>=1; i--){
	        if(i*(i+1) <= 2*n)
	            break;
	    }
	    cout << i << "\n";
	}
	return 0;
}
