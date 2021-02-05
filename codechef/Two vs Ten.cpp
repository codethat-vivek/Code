// Question Link - https://www.codechef.com/problems/TWOVSTEN

// Solution Link - https://www.codechef.com/viewsolution/36787415

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int a;
	    cin >> a;
	    if(a % 2 == 0 && a % 5 == 0)
	        cout << 0 << endl;
	    else if(a % 2 == 0 && a % 5 != 0)
	        cout << -1 << endl;
	    else if(a % 2 != 0 && a % 5 == 0)
	        cout << 1 << endl;
	    else 
	        cout << -1 << endl;
	}
	return 0;
}
