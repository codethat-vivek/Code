// Question Link - https://www.codechef.com/problems/FLOW005

// Solution Link - https://www.codechef.com/viewsolution/36489584

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, k;
	cin >> t;
	int arr[6] = {100, 50, 10, 5, 2, 1};
	while(t--){
	    cin >> k;
	    int cnt = 0;
	    for(int i=0; i<6; i++){
	        if(arr[i] <= k){
	            cnt += k/arr[i];
	            k = k%arr[i];
	        }
	    }
	    cout << cnt << endl;
	}
	return 0;
}
