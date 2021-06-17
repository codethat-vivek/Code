// Question Link - https://www.codechef.com/problems/TWOSTR

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string a, b;
	while(t--){
	    cin >> a >> b;
	    int i=0;
	    for(i=0; a[i] != '\0'; i++){
	        if(a[i] != b[i] && a[i] != '?' && b[i] != '?')
	            break;
	    }
	    if(a[i] != '\0')
	        cout << "No" << "\n";
	    else 
	        cout << "Yes" << "\n";
	}
	return 0;
}
