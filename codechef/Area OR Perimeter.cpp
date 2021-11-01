// Question Link - https://www.codechef.com/problems/AREAPERI

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int l, b;
	cin >> l >> b;
	int area = l*b;
	int perimeter = 2*(l+b);
	if(area > perimeter)
	    cout << "Area" << "\n" << area;
	else if(area < perimeter)
	    cout << "Peri" << "\n" << perimeter;
	else
	    cout << "Eq" << "\n" << area;
	return 0;
}
