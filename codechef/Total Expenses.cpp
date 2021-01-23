// Question Link - https://www.codechef.com/problems/FLOW009

// Solution Link - https://www.codechef.com/viewsolution/36702797

// SOLUTION - 

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	double quantity, price;
	while(t--){
	    cin >> quantity >> price;
	    if(quantity > 1000){
	        cout << setprecision(6) << fixed << quantity*price*0.9 << "\n";
	    }
	    else
	        cout << setprecision(6) << fixed << quantity*price << "\n";
	}
	return 0;
}
