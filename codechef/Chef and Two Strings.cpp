// Question Link - https://www.codechef.com/problems/CHEFSTLT

// Solution Link - https://www.codechef.com/viewsolution/36746069

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	string a, b;
	while(t--){
	    cin >> a >> b;
	    int i = 0, mm = 0, mx = 0;
	    while(a[i] != '\0'){
	        if(a[i] == '?' || b[i] == '?')
	            mx += 1;
	        else if(a[i] != b[i]){
	            mm += 1;
	            mx += 1;
	        }
	        
	        i++;
	    }
	    cout << mm << " " << mx << "\n";
	}
	return 0;
}
