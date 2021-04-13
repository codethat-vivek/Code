// Question Link - https://www.codechef.com/problems/SNCKYEAR

// Solution Link - https://www.codechef.com/viewsolution/36889047

// SOLUTION 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    if(n == 2015 || n == 2010 || n == 2016 || n == 2017 || n == 2019)
	        cout << "HOSTED" << "\n";
	    else
	        cout << "NOT HOSTED" << "\n";
	        
	}
	return 0;
}
