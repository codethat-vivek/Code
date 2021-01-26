// Question Link - https://www.codechef.com/problems/GDOG

// Solution Link - https://www.codechef.com/viewsolution/36745510

// SOLUTION - 


#include <iostream>
using namespace std;

int answer(int n, int k){
    int mx = 0;
    for(int i=1; i<=k; i++){
        if(mx < n%i)
            mx = n%i;
    }
    return mx;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, k;
	while(t--){
	    cin >> n >> k;
	    cout << answer(n, k) << endl;
	}
	return 0;
}
