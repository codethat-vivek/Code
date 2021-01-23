// Question Link - https://www.codechef.com/problems/SUMTRIAN

// Solution Link - https://www.codechef.com/viewsolution/36655541

// SOLUTION - 

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	int n;
	while(t--){
	    cin >> n;
	    int arr[n][n];
	    for(int i=0; i<n; i++){
	        for(int j=0; j<i+1; j++){
	            cin >> arr[i][j];
	        }
	    }
	    
	    // Logic
	    for(int i=n-1; i>0; i--){
	        for(int j=0; j<i; j++){
	            if(arr[i][j] < arr[i][j+1])
	                arr[i-1][j] += arr[i][j+1];
	            else
	                arr[i-1][j] += arr[i][j];
	        }
	    }
	    
	    cout << arr[0][0] << endl;
	    
	}
	return 0;
}
