// Question Link - https://www.codechef.com/problems/MUFFINS3

// Solution Link - https://www.codechef.com/viewsolution/36452974

// SOLUTION -

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t;
	int k;
	cin >> t; 
	while(t--){
	    
	    cin >> k;
	    
	    if(k == 2)
	        cout << 2 << endl;
	    else
	        cout << k/2 + 1 << endl;
	   
	}
	return 0;
}
