// Question Link - https://www.codechef.com/problems/RECIPE

// Solution Link - https://www.codechef.com/viewsolution/36701888

// SOLUTION - 

#include <iostream>
using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    
	    int hcf = gcd(arr[0], arr[1]);
	    for(int i=2; i<n-1; i++){
	        hcf = gcd(hcf, arr[i]);
	    }
	    for(int i=0; i<n; i++){
	        cout << arr[i]/hcf << " ";
	    }
	    cout << endl;
	    
	}
	return 0;
}
