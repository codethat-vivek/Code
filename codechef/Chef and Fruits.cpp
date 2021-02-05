// Question Link - https://www.codechef.com/problems/FRUITS

// Solution Link - https://www.codechef.com/viewsolution/36746407

// SOLUTION - 

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, m, k;
	while(t--){
	    cin >> n >> m >> k;
	    
	    if(k >= abs(m-n))
	        cout << 0 << "\n";
	    
	    else
	        cout << abs(m-n) - k << "\n";
	    
	}
	return 0;
}
