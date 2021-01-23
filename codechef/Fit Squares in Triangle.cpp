// Question Link - https://www.codechef.com/problems/TRISQ

// Solution Link - https://www.codechef.com/viewsolution/36658149

// SOLUTION - 

#include <iostream>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=1; i<=n; i++){
	        if(i == 1 || i == 2 || i == 3)
	            arr[i] = 0;
	        else if(i == 4)
	            arr[i] = 1;
	        else if(i % 2 == 0)
	            arr[i] = arr[i-2] + (i-2)/2;
	        else if(i % 2 != 0)
	            arr[i] = arr[i-1];
	    }
	    
	    cout << arr[n] << endl;
	    
	}
	return 0;
}
