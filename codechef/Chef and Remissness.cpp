// Question Link - https://www.codechef.com/problems/REMISS

// Solution Link - https://www.codechef.com/viewsolution/36488206

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a, b;
	while(t--){
	    cin >> a >> b;
	    if(a>b)
	        cout << a << " ";
	    else 
	        cout << b << " ";
	    cout << a+b << endl;
	}
	return 0;
}
