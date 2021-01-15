// Question Link - https://www.codechef.com/problems/CHOPRT

// Solution Link - https://www.codechef.com/viewsolution/36488646

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
	    if(a < b)
	        cout << "<" << endl;
	    else if(a > b)
	        cout << ">" << endl;
	    else 
	        cout << "=" << endl;
	}
	return 0;
}
