// Question Link - https://www.codechef.com/problems/ATM2

// Solution - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n, k;
	while(t--){
	    cin >> n >> k;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	        if(k >= arr[i]){
	            k -= arr[i];
	            cout << 1;
	        }
	        else
                cout << 0;

	    }
	    cout << endl;
	}
	return 0;
}
