// Question Link - https://www.codechef.com/problems/MISSP

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    int arr[n];
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	        ans = ans ^ arr[i];
	    }
	    cout << ans << endl;
	}
	return 0;
}
