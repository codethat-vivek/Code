// Question Link - https://www.codechef.com/problems/DIFFSUM

// Solution Link - https://www.codechef.com/viewsolution/36701657

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a, b;
	cin >> a >> b;
	 
	if(a>b)
	    cout << a-b << endl;
	else 
	    cout << a+b << endl;
	return 0;
}
