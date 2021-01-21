// Question Link - https://www.codechef.com/problems/PPSUM

// Solution Link - https://www.codechef.com/viewsolution/36702051

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int a;
	long n;
	while(t--){
	    cin >> a >> n;
	    long ans;
	    for(int i=0; i<a; i++){
	        ans = n*(n+1)/2;
	        n = ans;
	    }
	    cout << ans << endl;
	    
	}
	return 0;
}
