// Question Link - https://www.codechef.com/problems/DECINC

// Solution Link - https://www.codechef.com/viewsolution/36497335

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	if(n%4 == 0)
	    cout << n+1;
	else 
	    cout << n-1;
	return 0;
}
